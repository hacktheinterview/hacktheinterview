from backend.utils.model_choice_enum import ModelChoicesEnum, EnumValue


class ProblemName(ModelChoicesEnum):
	# ARRAY
	MIN_STEPS_IN_INFINITE_GRID = EnumValue("MIN_STEPS_IN_INFINITE_GRIDBOOKMARK", "Min Steps in Infinite Grid")


class ProblemSubCategory(ModelChoicesEnum):
	# ARRAY
	ARRAY_MATH            = EnumValue("ARRAY_MATH", "Math")
	ARRAY_SIMULATION      = EnumValue("ARRAY_SIMULATION", "Simulation")
	ARRAY_ARRANGEMENT     = EnumValue("ARRAY_ARRANGEMENT", "Arrangement")

	# LINKED LIST
	LINKED_LIST_2_POINTER = EnumValue("LINKED_LIST_2_POINTER", "List 2 Pointer")


class ProblemCategory(ModelChoicesEnum):
	ARRAY       = EnumValue("ARRAY", "Array")
	LINKED_LIST = EnumValue("LINKED_LIST", "Linked List")


class ProblemDifficultyType(ModelChoicesEnum):
	EASY   = EnumValue("EASY", "Easy")
	MEDIUM = EnumValue("MEDIUM", "Medium")
	HARD   = EnumValue("HARD", "Hard")


class CompanyName(ModelChoicesEnum):
	GOOGLE    = EnumValue("GOOGLE", "Google")
	FACEBOOK  = EnumValue("FACEBOOK", "Facebook")
	MICROSOFT = EnumValue("MICROSOFT", "Microsoft")


class LanguageType(ModelChoicesEnum):
	C_PLUS_PLUS      = EnumValue("C_PLUS_PLUS", "C++")
	JAVA             = EnumValue("JAVA", "Java")
	PYTHON           = EnumValue("PYTHON", "Python")
	JAVASCRIPT       = EnumValue("JAVASCRIPT", "Javascript")


class SubmissionStatus(ModelChoicesEnum):
	WAITING   = EnumValue("WAITING", "Waiting")
	COMPLETE  = EnumValue("COMPLETE", "Complete")


class SubmissionResult(ModelChoicesEnum):
	PASS = EnumValue("PASS", "Pass")
	COMPILE_ERROR = EnumValue("COMPILE_ERROR", "Compile Error")
	FAILED = EnumValue("FAILED", "Failed")


class TestCaseSubmissionStatus(ModelChoicesEnum):
	AWAITING_COMPILATION = EnumValue("-1", "Awaiting Compilation")
	DONE                 = EnumValue("0", "Done")
	COMPILING            = EnumValue("1", "Compiling")
	RUNNING              = EnumValue("3", "Running")


class TestCaseSubmissionResult(ModelChoicesEnum):
	NOT_RUN               = EnumValue("0", "Not Run")
	COMPILATION_ERROR     = EnumValue("11", "Compilation Error")
	RUNTIME_ERROR         = EnumValue("12", "Runtime Error")
	TIME_LIMIT_EXCEEDED   = EnumValue("13", "Time Limit Exceeded")
	SUCCESS               = EnumValue("15", "Success")
	MEMORY_LIMIT_EXCEEDED = EnumValue("17", "Memory Limit Exceeded")
	ILLEGAL_SYSTEM_CALL   = EnumValue("19", "Illegal System Call")
	INTERNAL_ERROR        = EnumValue("20", "Internal Error")

