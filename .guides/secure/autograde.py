#!/usr/bin/env python
import os
import random
import json

# import grade submit function
import sys

sys.path.append("/usr/share/codio/assessments")
from lib.grade import send_grade_v2, FORMAT_V2_MD, FORMAT_V2_HTML, FORMAT_V2_TXT

CODIO_UNIT_DATA = os.environ["CODIO_AUTOGRADE_ENV"]

# import grading function
import grade_assignment as ga


def main():
    # Execute the test on the student's code

    grade, feedback = ga.grade()

    # Send the grade back to Codio with the penalty factor applied
    res = send_grade_v2(grade, feedback, FORMAT_V2_MD)
    # res = send_grade_v2(grade, feedback, penalty=penalty) # if 'format' or/and 'extra credit' params are not in request then use penalty=penalty_value
    print(CODIO_UNIT_DATA)
    exit(0 if res else 1)


main()
