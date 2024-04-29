#!/usr/bin/env python3
import grade_assignment as ga


def main():
    # Execute the test on the student's code

    grade, feedback = ga.grade()
    print(f"{feedback}")
    print(f"\nTu nota actual sería: {grade}")


main()
