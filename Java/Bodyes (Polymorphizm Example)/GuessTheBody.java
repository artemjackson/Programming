public class GuessTheBody {
    public static void main(String args[])
    {
        Material metall = new Metall();
        metall.addProperty("expensive");

        Shape sphere=new Sphere();
        sphere.addProperty("rolls well");

        Body body = new Body();
        body.setMaterial(metall);
        body.setShape(sphere);

        body.printAllProperties();
    }
}
