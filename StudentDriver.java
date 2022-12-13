import java.util.ArrayList;
import java.util.HashMap;

class Course {

  String courseCode;
  String grade;

  Course() {
    courseCode = "";
    grade = "";
  }

  Course(String courseCode, String grade) {
    this.courseCode = courseCode;
    this.grade = grade;
  }
}

class Student {

  String name;
  String registerNumber;
  int semester;
  ArrayList<Course> courses = new ArrayList<Course>();
  HashMap<String, Integer> gradeToScore = new HashMap<String, Integer>();

  public Student(String name, String registerNumber, int semester, ArrayList<Course> courses) {
    this.name = name;
    this.registerNumber = registerNumber;
    this.semester = semester;
    this.courses = courses;
  }
  
  void calculateGPA() {
    int numCourses = courses.size();
    int scoreSum = 0;
    gradeToScore.put("S", 10);
    gradeToScore.put("A", 9);
    gradeToScore.put("B", 8);
    gradeToScore.put("C", 7);
    gradeToScore.put("D", 6);
    gradeToScore.put("E", 5);
    gradeToScore.put("F", 0);

    for (Course course : courses) {
      String currentGrade = course.grade;
      scoreSum += gradeToScore.get(currentGrade);
    }

    float gpa = scoreSum / numCourses;

    System.out.println(String.format("GPA = %.2f", gpa));
  }
}

public class StudentDriver {

  public static void main(String[] args) throws WrongGradeException {
    // Scanner sc = new Scanner(System.in);

    // System.out.println("Enter the name : ");
    String name = "Rohan";

    // System.out.println("Enter Register Number : ");
    String registerNumber = "21BCE3982";

    // System.out.println("Enter Number of courses : ");
    int numCourses = 3;
    // sc.nextLine();

    ArrayList<Course> courses = new ArrayList<Course>();
    courses.add(new Course("BMAT102L","S"));
    courses.add(new Course("BMAT102L","D"));
    courses.add(new Course("BMAT102L","S"));

    // String[] grades = { "S", "A", "B", "C", "D", "E", "F" };

    // for (int i = 0; i < numCourses; i++) {
    //   System.out.println("Enter Course Code : ");
    //   String courseCode = sc.nextLine();

    //   System.out.println("Enter Grade : ");
    //   String grade = sc.nextLine();

    //   if (!Arrays.asList(grades).contains(grade)) {
    //     throw new WrongGradeException();
    //   }

    //   courses[i] = new Course(courseCode, grade);
    // }

    Student student = new Student(name, registerNumber, numCourses, courses);
    student.calculateGPA();
  }
}

class WrongGradeException extends Exception {

  public WrongGradeException() {
    super("Wrong Grade Entered");
  }
}
