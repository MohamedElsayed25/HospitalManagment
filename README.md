🏥 Hospital Queue Management System
This is a simple console-based C++ program for managing patients in a hospital system. It allows users to add patients, prioritize urgent cases, and view or process the queue based on specializations.

📋 Features
Add a new patient with a specialization, name, and urgency level.

Print all patients across all specializations.

Get the next patient for a specific specialization.

Each specialization can queue up to 5 patients.

Urgent patients are added to the front of the queue; regular ones go to the end.

🛠 Technologies Used
C++,
Console I/O

🧪 Sample Input/Output
pgsql
Copy
Edit
Enter your choice
1) Add new patient
2) Print all patient
3) Get next patient
4) Exit
> 1
Enter specalization,name,statis: 3 John 1
markdown
Copy
Edit
> 2
****************************
there are 1 in specializatio 3
John Uregant
⚠️ Notes
Maximum of 20 specializations (indexed 0 to 19).

Maximum of 5 patients per specialization.

Urgent patients (status = 1) are added to the front; regular patients (status = 0) are added to the end.

The system loops until you choose option 4) Exit.
