CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    enrollment_year INT
);

ALTER TABLE Students
ADD COLUMN email VARCHAR(100);
ALTER TABLE Students
DROP COLUMN enrollment_year;

ALTER TABLE Students
ALTER COLUMN age TYPE SMALLINT;
ALTER TABLE Students
RENAME COLUMN name TO full_name;

CREATE INDEX idx_subject_name ON Subjects(subject_name);

ALTER TABLE Subjects
ADD CONSTRAINT credits_positive CHECK (credits > 0);


CREATE TABLE Professors (
    professor_id INT PRIMARY KEY,
    name VARCHAR(100),
    department VARCHAR(100),
    position VARCHAR(100)
);

CREATE TABLE Subjects (
    subject_id INT PRIMARY KEY,
    subject_name VARCHAR(100),
    credits INT
);

CREATE TABLE Student_Subjects (
    student_id INT,
    subject_id INT,
    enrollment_date DATE,
    PRIMARY KEY (student_id, subject_id),
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (subject_id) REFERENCES Subjects(subject_id)
);

CREATE TABLE Professor_Subjects (
    professor_id INT,
    subject_id INT,
    PRIMARY KEY (professor_id, subject_id),
    FOREIGN KEY (professor_id) REFERENCES Professors(professor_id),
    FOREIGN KEY (subject_id) REFERENCES Subjects(subject_id)
);

INSERT INTO Students (student_id, full_name, age, email) VALUES
(1, 'John Doe', 20, 'johndoe@example.com'),
(2, 'Jane Smith', 22, 'janesmith@example.com'),
(3, 'Alice Johnson', 19, 'alicejohnson@example.com'),
(4, 'Bob Brown', 21, 'bobbrown@example.com');

INSERT INTO Professors (professor_id, name, department, position) VALUES
(1, 'Dr. Thomas Anderson', 'Computer Science', 'Professor'),
(2, 'Dr. Emily Davis', 'Mathematics', 'Associate Professor'),
(3, 'Dr. Michael Clarke', 'Physics', 'Assistant Professor'),
(4, 'Dr. Sarah Wilson', 'History', 'Lecturer');

INSERT INTO Subjects (subject_id, subject_name, credits) VALUES
(1, 'Database Systems', 4),
(2, 'Calculus I', 3),
(3, 'Physics 101', 4),
(4, 'World History', 3);

INSERT INTO Student_Subjects (student_id, subject_id, enrollment_date) VALUES
(1, 1, '2024-09-01'),
(2, 2, '2024-09-02'),
(3, 3, '2024-09-03'),
(4, 4, '2024-09-04');

INSERT INTO Professor_Subjects (professor_id, subject_id) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4);

