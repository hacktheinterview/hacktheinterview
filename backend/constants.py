from backend.enums import Language
from hackerearth.parameters import SupportedLanguages

PROBLEM_ROOT_DIR = "problems/"

LANGUAGE_FILE_EXTENSION_MAP = {
	Language.C: '.c',
	Language.CPP: '.cpp',
	Language.JAVA: '.java',
	Language.PYTHON: '.py',
	Language.JAVASCRIPT: '.js'
}

HTI_TO_HACKER_EARTH_LANGUAGE_MAP = {
	Language.C: SupportedLanguages.C,
	Language.CPP: SupportedLanguages.CPP11,
	Language.JAVA: SupportedLanguages.JAVA,
	Language.PYTHON: SupportedLanguages.PYTHON,
	Language.JAVASCRIPT: SupportedLanguages.JAVASCRIPT
}
