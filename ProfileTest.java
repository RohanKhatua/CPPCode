import java.time.LocalDate;
import java.time.Period;
import java.util.Scanner;

class Address{
    String streetName;
    String city;
    String state;
    String pincode;

    Address(String streetName, String city, String state, String pincode){
        this.streetName = streetName;
        this.city = city;
        this.state = state;
        this.pincode = pincode;
    }
}

class Profile{
    private String name;
    private LocalDate dateOfBirth;
    private Address address;

    Profile(String name, LocalDate dateOfBirth, Address address){
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public LocalDate getDateOfBirth() {
        return dateOfBirth;
    }

    public Address getAddress() {
        return address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDateOfBirth(LocalDate dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    @Override
    public String toString() {
        // return "Profile [name=" + name + ", dateOfBirth=" + dateOfBirth + ", address=" + address + "]";
        String profileData = "Name : "+name+"\n";
        String dobData = "DOB :"+dateOfBirth.getDayOfMonth()+"/"+dateOfBirth.getMonthValue()+"/"+dateOfBirth.getYear();
        String addressData = "Street Name = "+address.streetName+"\nCity = "+address.city+"\nState = "+address.state+"\nPincode = "+address.pincode;
        return profileData+dobData+addressData;
    }

    public int calculateAge(){
        Period age = Period.between(dateOfBirth, LocalDate.now());
        return age.getYears();        
    }


}

public class ProfileTest {
    public static void main(String[] args) throws InvalidAgeException{
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Name : ");
        String name = sc.nextLine();

        System.out.print("Enter Date of Birth in DD/MM/YYYY format : ");
        String date = sc.nextLine();
        int day = Integer.valueOf(date.substring(0,2));
        int month = Integer.valueOf(date.substring(3, 5));
        int year = Integer.valueOf(date.substring(7, date.length()));

        LocalDate dob = LocalDate.of(year, month, day);

        System.out.print("Enter Street Name : ");
        String streetName = sc.nextLine();
        System.out.print("Enter City : ");
        String city = sc.nextLine();
        System.out.print("Enter State : ");
        String state = sc.nextLine();
        System.out.print("Enter Pin Code : ");
        String pincode = sc.nextLine();

        Address address = new Address(streetName, city, state, pincode);

        Profile profile = new Profile(name, dob, address);

        if (profile.calculateAge() < 18) throw new InvalidAgeException();
        else System.out.println("You are eligible to vote");

        System.out.println(profile.toString());
    }
}

class InvalidAgeException extends Exception{
    InvalidAgeException(){
        super("You are not eligible to vote");
    }
}
