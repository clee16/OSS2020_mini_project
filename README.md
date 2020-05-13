# OSS2020_mini_project

Introduction
============
Project Name
------------
Academic Member List Management

Purpose
-------
Since academic activities vary from semester to semester,    
it is necessary to create a management program that is easy to create,read,update and delete.   

Functions
---------
1. Create
- Create a new data record from a data file
- Create a new member record from teh standard input
2. Read
- According to user specified conditions, print a record, multiple or all records to the sandard output
- Read/Write the entire data from/to filesystem
- Export the entire data in a report format as a .txt file
3. Update
- Update a specific field of a record, multiple or all records
4. Delete
- Delete a record, multiple or all records 
5. Sorting
- Arrange (sort) the order of data records 
6. Statistics
- Organize and Show the results at a glance after sorting

Basic Configuration frame
-------------------------
1. Total 3 .h file
- base.h: create, read
- extras.h: update, delete, etc
- record.h: struct
2. Total 3 .txt file
- origin.txt: used to function as a file that exists in the first place(directly created) regardless    
whether the program is running or not
- data.txt: during the program, the information is continuously stored.
- report.txt: text document used to store final records in standardized.
