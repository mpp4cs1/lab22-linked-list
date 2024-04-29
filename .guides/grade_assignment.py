#!/usr/bin/env python3
import os
import subprocess
import re


def isRecursive(code, name):
    return name in extractBody(code, name)


def findFunction(code, name):
    return code.find(name)


def extractBody(code, name):
    start = findFunction(code, name)
    if start < 0:
        return ""
    i = start
    while code[i] != "{" and i < len(code):
        i = i + 1
    if i >= len(code):
        return ""
    body = code[i]
    depth = 1
    i = i + 1
    while depth > 0 and i < len(code):
        if code[i] == "{":
            depth = depth + 1
        elif code[i] == "}":
            depth = depth - 1
        body = body + code[i]
        i = i + 1
    if i >= len(code):
        return ""
    return body


def grade():
    mark, feedback = gradeCatch(
        "test.cpp",
        checkSource,
        ["-lCatch2Main", "-lCatch2"],
        "test",
        "--benchmark-no-analysis --success",
    )
    return mark, feedback


def checkSource(sourcePath):
    print("Comprobando el código fuente...")
    feedback = "\n"
    baseDir = os.path.dirname(sourcePath)
    functionsHpp = os.path.join(baseDir, "llist.hpp")
    if not os.path.exists(functionsHpp):
        feedback = feedback + f"No se encontró el archivo: {functionsHpp}.\n"
        return False, feedback
    with open(functionsHpp) as sourceFile:
        source = sourceFile.read()
        if not "insert_after" in source:
            feedback = (
                feedback
                + f"Falta la definición de la función 'insert_after' en {functionsHpp}.\n"
            )
            return False, feedback
        if not "push" in source:
            feedback = (
                feedback
                + f"Falta la definición de la función 'push' en {functionsHpp}.\n"
            )
            return False, feedback
    feedback = feedback + "\nEl código fuente cumple las especificaciones.\n"
    print("El código fuente cumple las especificaciones.")
    return True, feedback


def compile(sourceFilename, binFilename, flags):
    print(f"Compilando {sourceFilename}...")
    commandline = ["g++", sourceFilename, "-o", binFilename]
    commandline.extend(flags)
    compilationResult = subprocess.run(
        commandline,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    print("Compilación completada.")
    return compilationResult


def run(binFilename, commandlineArguments):
    commandline = binFilename + " " + commandlineArguments
    print(f"Ejecutando {commandline}...")
    output = subprocess.run(
        [commandline],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        shell=True,
    )
    print("Ejecución completada.")
    return output


def gradeCatch(
    sourceFilename, checkSource, compilerFlags, binFilename, commandlineArguments
):
    feedback = ""
    basePath = os.path.expanduser(".")
    sourcePath = os.path.join(basePath, sourceFilename)
    if not os.path.exists(sourcePath):
        feedback = (
            feedback
            + f"No se encuentra el archivo fuente. El archivo fuente debe llamarse {sourceFilename}."
        )
        return 0, feedback
    if checkSource:
        sourceOK, sourceFeedback = checkSource(sourcePath)
        feedback = feedback + "\n\n" + sourceFeedback
        if not sourceOK:
            feedback = feedback + f"\n\n### Mark for {sourceFilename} is 0\n\n"
            return 0, feedback
    programPath = os.path.join(basePath, binFilename)
    compilationResult = compile(sourceFilename, binFilename, compilerFlags)
    feedback = feedback + compilationResult.stdout.decode() + "\n"
    if compilationResult.returncode != 0:
        feedback = feedback + compilationResult.stderr.decode() + "\n"
        feedback = (
            feedback
            + f"El ejercicio {sourceFilename} tiene errores de compilación. Intenta corregir los errores mencionados arriba."
        )
        return 0, feedback

    feedback = feedback + "\n"
    output = run(programPath, commandlineArguments)
    outputText = output.stdout.decode().strip()
    feedback = feedback + outputText
    if output.returncode == 0:
        feedback = feedback + "\nEl programa ha superado con éxito todas las pruebas.\n"
        return 10, feedback
    else:
        outputLines = outputText.splitlines(False)
        resultRE = re.compile(
            "test cases: ([0-9]*)[ |]*([0-9]*) passed[ |]*([0-9]*) failed.*"
        )
        for line in outputLines:
            testCasesLine = resultRE.match(line)
            if testCasesLine:
                testCases = testCasesLine.group(1)
                passed = testCasesLine.group(2)
                return 10 * int(passed) / int(testCases), feedback
        feedback = (
            feedback
            + "\nAlgo falla en la ejecución: no se encuentran los números de casos de prueba.\n"
        )
        return 0, feedback
