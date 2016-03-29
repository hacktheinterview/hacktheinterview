from backend.utils.model_choice_enum import ModelChoicesEnum, EnumValue

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


class ProblemDifficulty(ModelChoicesEnum):
	EASY   = EnumValue("EASY", "Easy")
	MEDIUM = EnumValue("MEDIUM", "Medium")
	HARD   = EnumValue("HARD", "Hard")

class LanguageName(ModelChoicesEnum):
	C_PLUS_PLUS      = EnumValue("1", "C++")
	JAVA             = EnumValue("10", "Java")
	PYTHON           = EnumValue("4", "Python")
	JAVASCRIPT       = EnumValue("35", "Javascript")


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
