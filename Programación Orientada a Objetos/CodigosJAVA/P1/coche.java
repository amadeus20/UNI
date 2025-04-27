public class coche{
    private String marca;
    private String modelo;
    private int anio;
    int b;
    public static int add(int a, int b) {
        return a + b;
  
    }
    public static int sub(int a, int b) {
        return a - b;
  
    }
    public static double div(double a, int b) {
    return a / b;
  
}
    public coche(String marca, String modelo, int anio){
    this.marca=marca;
    this.modelo=modelo;
    this.anio=anio;

}
    public void mostrarDatos(){
    System.out.println("Marca: "+marca );
    System.out.println("Modelo: "+modelo);
    System.out.println("Año: "+anio);
}
    public void acelerar(){
    System.out.println("El coche esta acelerando");
}
    public static void mostrarMensaje(){
    System.out.println("Este es un mensaje estatico");
}
public static void main(String[] args) {
    coche coche1 = new coche("Toyota", "Corolla", 2020);
    coche1.mostrarDatos();
    coche1.acelerar();
    coche.mostrarMensaje();
}
}


