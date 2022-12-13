import java.util.Scanner;

class ComplexNumberException extends Exception{
    ComplexNumberException(){
        super("Badly Formatted Complex Number");
    }
}

class Complex{
    private float realPart;
    private float imaginaryPart;

    Complex(){
        this.realPart=0;
        this.imaginaryPart=0;
    }

    Complex(float realPart, float imaginaryPart){
        this.realPart = realPart;
        this.imaginaryPart = imaginaryPart;
    }

    public float getRealPart() {
        return realPart;
    }

    public void setRealPart(float realPart) {
        this.realPart = realPart;
    }

    public float getImaginaryPart() {
        return imaginaryPart;
    }

    public void setImaginaryPart(float imaginaryPart) {
        this.imaginaryPart = imaginaryPart;
    }

    public static Complex add(Complex c1, Complex c2){
        Complex res = new Complex();
        res.setRealPart(c1.realPart+c2.realPart);
        res.setImaginaryPart(c1.imaginaryPart+c2.imaginaryPart);
        return res;
    }

    @Override
    public String toString(){

        String res  = realPart+"";
        //System.out.println(realPart+""+imaginaryPart+"i");
        if (imaginaryPart<0){
            res+="-"+imaginaryPart+"i";
        }

        else {
            res+="+"+imaginaryPart+"i";
        }

        return res;
    }

    public static Complex getComplex (String c1) throws ComplexNumberException{
        Complex c = new Complex();
        String real;
        String imaginary;        

        if (c1.indexOf("i")==-1) throw new ComplexNumberException();
        if (c1.indexOf("+")==-1 && c1.indexOf("-")==-1) throw new ComplexNumberException();

        int start = 0;
        if (c1.charAt(0)=='-') start=1; 
        
        for (int i =start;i<c1.length();i++){
            char ch = c1.charAt(i);
            if (!Character.isDigit(ch) && ch!='.' && ch!='i'){
                real = c1.substring(0, i);                
                
                if (c1.charAt(c1.length()-1)!='i'){
                    imaginary = c1.substring(i+2, c1.length());
                }
                else imaginary = c1.substring(i+1, c1.length()-1);
                
                if (ch!='+' && ch!='-') throw new ComplexNumberException();         
                else {
                    float realPart = Float.parseFloat(real);
                    float imaginaryPart = Float.parseFloat(imaginary);

                    c.setRealPart(realPart);
                    c.setImaginaryPart(imaginaryPart);

                    return c;
                }
            }
        }

        return new Complex();


    }
    
}

public class ComplexTest {

    public static void main(String[] args) throws ComplexNumberException {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter C1 : ");
            String c1 = sc.nextLine();

            System.out.print("Enter C2 : ");
            String c2 = sc.nextLine();
            
            Complex ca = Complex.getComplex(c1);
            Complex cb = Complex.getComplex(c2);

            Complex sum = Complex.add(ca, cb);

            System.out.println("The Sum is "+sum.getRealPart()+"+"+sum.getImaginaryPart()+"i");
        }
        
    }

    

}

