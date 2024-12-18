# CS300

### 1. **What was the problem you were solving in the projects for this course?**

The problem involved creating an advising assistance program to help users manage course information for the Computer Science department at ABCU. The program needed to load course data from a CSV file, store it in an efficient data structure, and allow users to:
- View a sorted list of courses.
- Retrieve specific course details, including prerequisites.
- Ensure the program could handle user errors gracefully while maintaining performance and usability.

---

### 2. **How did you approach the problem? Consider why data structures are important to understand.**

I approached the problem by first analyzing the requirements and selecting the most suitable data structure. I chose a hash table (`std::unordered_map`) for its efficiency in storing and retrieving course information. Hash tables provide O(1) average-case complexity for lookups, which is ideal for quickly finding courses by their IDs. Data structures are essential because they influence how efficiently and effectively we can manipulate and retrieve data, which directly impacts the user experience.

---

### 3. **How did you overcome any roadblocks you encountered while going through the activities or project?**

When parsing the CSV file, I encountered formatting inconsistencies in the input data, such as missing fields or extra delimiters. To resolve this, I implemented robust error handling to skip malformed lines and provide meaningful feedback to the user. Additionally, managing dynamic user inputs required careful use of validation techniques to ensure the program handled unexpected inputs gracefully. Online resources, debugging tools, and iterative testing helped overcome these challenges.

---

### 4. **How has your work on this project expanded your approach to designing software and developing programs?**

This project highlighted the importance of planning and modularity in software design. By breaking down the program into well-defined functions (e.g., `loadFileData`, `printSortedCourses`, `printCourseDetails`), I ensured each component had a clear purpose and was easier to test and debug. I also learned the value of considering scalability, as the choice of data structures and algorithms impacts performance when dealing with larger datasets.

---

### 5. **How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**

I focused on writing clean, well-documented code with meaningful variable names and inline comments to make the program maintainable. I also incorporated industry best practices, such as separating logic into distinct functions and using error handling for robust user interaction. These practices ensure the program can be easily understood and modified by others or adapted for future requirements, such as supporting additional features or integrating with new data formats.
