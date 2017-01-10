import java.util.Scanner;

class Quiz {
  public Quiz(String n, int num) {
    nom = n;
    nombre = num;
    score = 0;
  }

  public void calculScore() {
    Scanner sc = new Scanner(System.in);
    int resultat;
    for (int i = 1; i <= 10; ++i) {
      System.out.printf("%d X %d = ", i, nombre);
      resultat = sc.nextInt();

      if (i * nombre == resultat) {
        System.out.println("Correct");
        score += 1;
      } else {
        System.out.println("Faux!");
      }
    }
    System.out.printf("%s! votre score est: %d/10\n", nom, score);
  }

  private String nom;
  private int nombre;
  private int score;
}

public class MultiQuiz {
  public static void main(String[] args) {
    String n;
    int num = 0;
    Scanner sc = new Scanner(System.in);
    System.out.println("\nEntrer votre nom: ");
    n = sc.next();
    System.out.println("\nEntrer le chiffre de quiz: ");
    num = sc.nextInt();
    Quiz Q = new Quiz(n, num);
    Q.calculScore();
  }
}
