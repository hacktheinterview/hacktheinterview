"""
	Base class for Enums to be used with choices for model fields.

	Usage:
		class TestChoices(ModelChoicesEnum):
			CHOICE1 = EnumValue(value1, "verbose name 1")
			CHOICE2 = EnumValue(value2, "verbose name 2")
			CHOICE3 = EnumValue(value3, "verbose name 3")

	TestChoices.CHOICE1 == value1 # True

	TestChoices.choices()
		returns [(value1, "verbose name 1"), (value2, "verbose name 2"), (value3, "verbose name 3")]
	TestChoices.choices() can be used directly for field.choices.

	TestChoices.validateValue("random") - raises ValueError
	TestChoices.validateValue(TestChoices.CHOICE1) - finishes without error

	TestChoices.verboseName(TestChoices.CHOICE1)
		returns "verbose name 1"

	IMPORTANT: The choice fields on the enum class must be named with all caps to be picked up as choices.

	Further examples:
		- general_utils.tests.test_model_choice_enum
		- zenefits_payroll.enums
"""

from six import with_metaclass


class EnumValue(object):
	"""
		Class to be used to specify values on an enum. This opens up possibilities of some further abstraction
		and extensibility.
		However the reason that makes this class mandatory is the need to maintain the order in which enum
		values have been defined on their class. Django uses this approach as well.
		python 3 has capabilities that allow ordering without needing a field class such as this one
	"""
	counter = 0

	def __init__(self, value, verboseName):
		self.value = value
		self.verboseName = verboseName
		EnumValue.counter += 1
		self.counter = EnumValue.counter

	def modelFieldChoice(self):
		return (self.value, self.verboseName)

	def __lt__(self, other):
		return self.counter < other.counter


class ModelChoicesEnumMeta(type):
	"""
		Meta class for ModelChoicesEnum
	"""
	def __init__(cls, name, bases, attrs):
		# Get all the all caps class variables (enum values)
		enumValues = {}  # will contain attribName : (value, verboseName)
		seenValues = set()
		for attr in attrs:
			enumValue = attrs[attr]
			if not isinstance(enumValue, EnumValue):
				# simply ignore anything that is not an EnumValue instance
				continue

			if enumValue.value in seenValues:
				raise Exception("Multiple enum fields found with the value %s for enum %s. Please check" +
									" the enum definition again" % (enumValue.value, name))
			seenValues.add(enumValue.value)

			enumValue.name = attr
			enumValues[attr] = enumValue
			setattr(cls, attr, enumValue.value)

		cls._enumValues = enumValues


class ModelChoicesEnum(with_metaclass(ModelChoicesEnumMeta, object)):
	"""
		Base class for creating enums to use for choices in models
		Usage:
			class TestChoices(ModelChoicesEnum):
				CHOICE1 = EnumValue(value1, "verbose name 1")
				CHOICE2 = EnumValue(value2, "verbose name 2")
				CHOICE3 = EnumValue(value3, "verbose name 3")

		TestChoices.CHOICE1 == value1 # True

		TestChoices.choices()
			returns [(value1, "verbose name 1"), (value2, "verbose name 2"), (value3, "verbose name 3")]
		TestChoices.choices() can be used directly for field.choices.

		TestChoices.validateValue("random") - raises ValueError
		TestChoices.validateValue(TestChoices.CHOICE1) - finishes without error

		TestChoices.verboseName(TestChoices.CHOICE1)
			returns "verbose name 1"

		IMPORTANT: only fields with an instance of EnumValue as their value are picked up
	"""
	@classmethod
	def choices(cls):
		return [enumValue.modelFieldChoice() for enumValue in sorted(cls._enumValues.values())]

	@classmethod
	def keys(cls):
		return [enumValue.value for enumValue in sorted(cls._enumValues.values())]

	@classmethod
	def validateValue(cls, value):
		"""
			Validate that the specified value is a valid Enum Value
		"""
		matches = [enumVal for enumVal in cls._enumValues.values() if enumVal.value == value]
		if len(matches) != 1:
			raise ValueError("Invalid value provided for enum %s: %s" % (cls.__name__, value))

	@classmethod
	def verboseName(cls, value):
		matches = [enumVal for enumVal in cls._enumValues.values() if enumVal.value == value]
		if len(matches) != 1:
			raise ValueError("Invalid value provided for enum %s: %s" % (cls.__name__, value))
		return matches[0].verboseName

	@classmethod
	def name(cls, value):
		try:
			return [k for k, v in cls._enumValues.iteritems() if v == value][0]
		except IndexError:
			raise ValueError(u"Invalid value for enum %s: %s" % (cls.__name__, value))
