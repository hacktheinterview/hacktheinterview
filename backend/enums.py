from backend.utils.model_choice_enum import ModelChoicesEnum, EnumValue

class ProblemSubCategory(ModelChoicesEnum):
	# ARRAY
	ARRAY_MATH            = EnumValue("ARRAY_MATH", "Math")
	ARRAY_SIMULATION      = EnumValue("ARRAY_SIMULATION", "Simulation")
	ARRAY_ARRANGEMENT     = EnumValue("ARRAY_ARRANGEMENT", "Arrangement")

	# LINKED LIST
	LINKED_LIST_2_POINTER = EnumValue("LINKED_LIST_2_POINTER", "List 2 Pointer")
	LINKED_LIST_BASIC   = EnumValue("LINKED_LIST_BASIC", "Linked List problems")

class ProblemCategory(ModelChoicesEnum):
	ARRAY       = EnumValue("ARRAY", "Array")
	LINKED_LIST = EnumValue("LINKED_LIST", "Linked List")


class ProblemDifficulty(ModelChoicesEnum):
	EASY   = EnumValue("EASY", "Easy")
	MEDIUM = EnumValue("MEDIUM", "Medium")
	HARD   = EnumValue("HARD", "Hard")

class LanguageName(ModelChoicesEnum):
	C                = EnumValue("C", "C")
	C_PLUS_PLUS      = EnumValue("C++", "C++")
	JAVA             = EnumValue("JAVA", "Java")
	PYTHON           = EnumValue("PYTHON", "Python")
	JAVASCRIPT       = EnumValue("JAVASCRIPT", "Javascript")


class SubmissionStatus(ModelChoicesEnum):
	PENDING = EnumValue("PENDING", "Pending")
	CE      = EnumValue("CE", "Compilation Error")
	AC      = EnumValue("AC", "Correct Answer")
	WA      = EnumValue("WA", "Wrong Answer")
	TLE     = EnumValue("TLE", "Time Limit Exceeded")
	MLE     = EnumValue("MLE", "Memory Limit Exceeded")
	OTHER   = EnumValue("OTHER", "Reason Not Yet found")


# class SubmissionResult(ModelChoicesEnum):
# 	PASS = EnumValue("PASS", "Pass")
# 	COMPILE_ERROR = EnumValue("COMPILE_ERROR", "Compile Error")
# 	FAILED = EnumValue("FAILED", "Failed")


# class TestCaseSubmissionStatus(ModelChoicesEnum):
# 	AWAITING_COMPILATION = EnumValue("-1", "Awaiting Compilation")
# 	DONE                 = EnumValue("0", "Done")
# 	COMPILING            = EnumValue("1", "Compiling")
# 	RUNNING              = EnumValue("3", "Running")


# class TestCaseSubmissionResult(ModelChoicesEnum):
# 	NOT_RUN               = EnumValue("0", "Not Run")
# 	COMPILATION_ERROR     = EnumValue("11", "Compilation Error")
# 	RUNTIME_ERROR         = EnumValue("12", "Runtime Error")
# 	TIME_LIMIT_EXCEEDED   = EnumValue("13", "Time Limit Exceeded")
# 	SUCCESS               = EnumValue("15", "Success")
# 	MEMORY_LIMIT_EXCEEDED = EnumValue("17", "Memory Limit Exceeded")
# 	ILLEGAL_SYSTEM_CALL   = EnumValue("19", "Illegal System Call")
# 	INTERNAL_ERROR        = EnumValue("20", "Internal Error")
