public class P2 {

    public static int a=4;
    public static int b=3;
    public static boolean c;
    public static String objeto;

    // Constructor
    public P2(int a, int b, boolean c, String objeto){
        P2.a = a;
        P2.b = b;
        P2.c = c;
        P2.objeto = objeto;
    }

    public void Imprimir(){
        System.out.println("El valor de a es: " + a);
        System.out.println("El valor de b es: " + b);
        System.out.println("El valor de c es: " + c);
        System.out.println("El objeto es: " + objeto);
    }
    
    public static void main(String[] args) {

        P2 Datos = new P2(a,b,c,objeto);
        Datos.Imprimir();
    }
    
}