import csv
from cs50 import SQL

db = SQL("sqlite:///newstudents.db")
# row = db.execute("select * from students;")
# print(row)

file = open("students.csv")
reader = csv.DictReader(file)

# for row in reader:
#     try:
#         # print(row['student_name'])
#         houses = db.execute ("select * from houses;")
#         if all(row['house'] not in i['house_name'] for i in houses):
#             db.execute("INSERT INTO houses VALUES (?,?,?)",None,row['house'],row['head'])
#     except ValueError as e:
#         print("Error: ", e)


# for row in reader:
#     try:
#         print(row)
#         student_id = db.execute("select id from students where students_name = ?", row['student_name'])
#         print(student_id)
#         house_id = db.execute ("select house_id from houses where house_name =?", row['house'])
#         print(house_id)
#         db.execute("INSERT INTO assignment VALUES (?,?)", int(student_id[0]['id']),int(house_id[0]['house_id']))
#     except ValueError as e:
#         print("Error: ", e)

students = db.execute ("select * from students")
houses = db.execute ("select * from houses")
assignment = db.execute ("select * from assignment")



print("NOW PRINTING FROM DB")
# for row in students:
#     print(row)
# for row in houses:
#     print(row)
# for row in assignment:
#     print(row)

final = db.execute("SELECT * FROM students, houses, assignment where students.id = assignment.student_id AND houses.house_id = assignment.house_ID")
for row in final:
    print(row['id'],",",row['students_name'],",",row['house_name'], ",",row['head'])

