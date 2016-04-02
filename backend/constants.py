from backend.enums import LanguageName
from hackerearth.parameters import SupportedLanguages

PROBLEM_ROOT_DIR = "problems/"

LANGUAGE_FILE_EXTENSION_MAP = {
	LanguageName.C: '.c',
	LanguageName.CPP: '.cpp',
	LanguageName.JAVA: '.java',
	LanguageName.PYTHON: '.py',
	LanguageName.JAVASCRIPT: '.js'
}

HTI_TO_HACKER_EARTH_LANGUAGE_MAP = {
	LanguageName.C: SupportedLanguages.C,
	LanguageName.CPP: SupportedLanguages.CPP11,
	LanguageName.JAVA: SupportedLanguages.JAVA,
	LanguageName.PYTHON: SupportedLanguages.PYTHON,
	LanguageName.JAVASCRIPT: SupportedLanguages.JAVASCRIPT
}
