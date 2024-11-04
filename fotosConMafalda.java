import java.util.*;

public class fotosConMafalda {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> mural = new ArrayList<>();
        while (true) {
            int numeroCasos;
            int numFotos = 0;
            // int numNoFotos = 0;
            // Numero de casos
            numeroCasos = scanner.nextInt();
            if (numeroCasos == 0) {
                scanner.close();
                return;
            }
            // Personajes en la cola
            for (int i = 0; i <= numeroCasos; i++) {
                String nombre = scanner.nextLine();
                mural.add(nombre);
            }
            // Hacer fotos
            ArrayList<String> foto = new ArrayList<>();
            for (int i = 0; i < mural.size(); i++) {
                String nombre = mural.get(i);
                // Se añade a la foto si no hay otro ocupando ese personaje
                if (!foto.contains(nombre)) {
                    foto.add(nombre);
                }
                // Si esta mafalda en la foto y hay minimo 3 personajes, se hace la foto
                System.out.println(foto.size());
                if (foto.size() >= 3 && foto.contains("Mafalda")) {
                    System.out.println("Foto hecha");
                    numFotos++;
                    // Las personas que ya se han hecho la foto, se van de la cola
                    i = 0;
                    for (String persona : new ArrayList<>(foto)) {
                        Iterator<String> iterator = mural.iterator();
                        while (iterator.hasNext()) {
                            if (iterator.next().equals(persona)) {
                                iterator.remove();
                                break;
                            }
                        }
                    }
                    foto.clear();
                }
            }
            foto.clear();
            System.out.println(numFotos + " " + mural.size());
        }
    }
}