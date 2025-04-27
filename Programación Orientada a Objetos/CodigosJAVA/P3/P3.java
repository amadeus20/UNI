import java.util.Scanner;
// Nombre: P3.java
public class P3 {

  public String nombre ;
  public int edad;
  public String ciudad;

  // Constructor
  public P3(String nombre, int edad, String ciudad) {
    this.nombre = nombre;
    this.edad = edad;
    this.ciudad = ciudad;
  }
  //Metodo para mostrar los datos
  public void mostrarDatos(){
    System.out.println("_____________Tus datos son: _____________");
    System.out.println("Nombre: "+nombre );
    System.out.println("Edad: "+edad);
    System.out.println("Ciudad: "+ciudad);
    System.out.println("__________________________");
  }
  public void PedirDatos(){
    Scanner scanner = new Scanner(System.in);

    System.out.println("¡Bienvenido!");
    System.out.println("Por favor, ingresa tus datos personales.");

    System.out.println("Como te llamas?");
    this.nombre = scanner.next();
    System.out.println("Cuantos años tienes?");
    this.edad = scanner.nextInt();
    System.out.println("De que ciudad eres?");
    this.ciudad = scanner.next();

    scanner.close();
  }

  public void main(String[] args) {
    
    P3 persona = new P3(nombre, edad, ciudad);
    persona.PedirDatos();
    persona.mostrarDatos();


    
  }

}
