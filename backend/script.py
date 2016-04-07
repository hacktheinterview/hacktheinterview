import os

d = {'.c': '//', '.cpp': '//', '.java': '//', '.py': '#'}

FOLDER_PATH = '/Users/aayushbahuguna/workspace/hacktheinterview/problems'
SOURCES = ['header', 'skeleton', 'solution', 'footer']
def generateFiles(problem_id):
    problemDir = os.path.join(FOLDER_PATH, str(problem_id))
    extensions = ['.c', '.cpp', '.java', '.py']
    for extension in extensions:
        path = os.path.join(problemDir, "Main" + extension)
        f = open(path, 'r')
        parts = f.read().split(d[extension] + "--SPLIT--")
        f.close()
        parts[1] = parts[1].replace(d[extension], '')
        for i, source in enumerate(SOURCES):
            sourcePath = os.path.join(problemDir, SOURCES[i] + extension)
            with open(sourcePath, 'w') as f:
                f.write(parts[i])


def removeFiles(problem_id):
    problemDir = os.path.join(FOLDER_PATH, str(problem_id))
    files = os.listdir(problemDir)
    for file in files:
        if file.endswith(".class") or file.endswith(".out") or file.endswith(".tmp"):
            os.remove(os.path.join(problemDir, file))
        for source in SOURCES:
            if file.startswith(source):
                os.remove(os.path.join(problemDir, file))