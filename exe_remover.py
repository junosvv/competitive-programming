import os

def f(dr):
    drs, files = next(os.walk(dr))[1:3]
    for file in files:
        if file.startswith("tempCodeRunnerFile.") or file.endswith(".exe") and (file[:-4]+".py" in files or file[:-4]+".cpp" in files):
            os.remove(dr+"/"+file)
        #if not file.startswith("tempCodeRunnerFile.") and file.endswith(".exe") and file[:-4]+".py" not in files and file[:-4]+".cpp" not in files:
        #    print("dangling", dr+"/"+file)
    for dr2 in drs:
        if dr2 != ".git" and dr2 != ".vscode":
            f(dr+"/"+dr2)

f(".")
