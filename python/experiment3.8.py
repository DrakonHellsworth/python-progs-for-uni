cgpa_ranges = [(0, 3.4, "F"), (3.5, 5.0, "C+"), (5.1, 6.0, "B"), (6.1, 7.0, "B+"), (7.1, 8.0, "A"), (8.1, 9.0, "A+"), (9.1, 10.0, "O")]

pds = float(input("Enter marks in PDS: "))
python = float(input("Enter marks in Python: "))
chemistry = float(input("Enter marks in Chemistry: "))
english = float(input("Enter marks in English: "))
physics = float(input("Enter marks in Physics: "))

total_marks = pds + python + chemistry + english + physics
percentage = (total_marks / 500) * 100
cgpa = percentage / 10

for min, max, grade in cgpa_ranges:
    if cgpa >= min and cgpa <= max:
        break

print("Gradesheet:")
print("Name: Rohit Sharma")
print("Roll Number: R17234512")
print("SAPID: 50005673")
print("Sem: 1")
print("Course: B.Tech. CSE AI&ML")
print("Subject name: Marks")
print("PDS:", pds)
print("Python:", python)
print("Chemistry:", chemistry)
print("English:", english)
print("Physics:", physics)
print("Percentage:", percentage)
print("CGPA:", cgpa)
print("Grade:", grade)