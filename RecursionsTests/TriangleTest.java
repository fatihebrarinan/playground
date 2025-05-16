package RecursionsTests;
public class TriangleTest {
    public static void main(String[] args) {
        Triangle triangle = new Triangle(5);
        System.out.println("Area of triangle with width 5: " + triangle.getArea());
        
        Triangle triangle2 = new Triangle(10);
        System.out.println("Area of triangle with width 10: " + triangle2.getArea());
        
        Triangle triangle3 = new Triangle(1);
        System.out.println("Area of triangle with width 1: " + triangle3.getArea());
    }
}
