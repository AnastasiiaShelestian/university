class Animal {

    String name;
    String color;
    int age;

    public Animal(String name, String color, int age) {
        setName(name);
        setColor(color);
        setAge(age);
    }

    public void setName(String name) {
        if (name.matches("^[a-zA-Z]+$")) {
            this.name = name;
        } else throw new IllegalArgumentException("Name must contain only letters");
    }

    public void setColor(String color) {
        if (color.matches("^[a-zA-Z]+$")) {
            this.color = color;
        } else throw new IllegalArgumentException("Color must contain only letters");
    }

    public void setAge(int age) {
        if (age > 0 && age < 100) {
            this.age = age;
        } else throw new IllegalArgumentException("Age must be between 1 and 99");
    }

    public String getName() {
        return name;
    }

    public String getColor() {
        return color;
    }

    public int getAge() {
        return age;
    }

    public String toString() {
        return "Animal name=" + name + ", color=" + color + ", age=" + age;

    }

    public boolean equals(Object obj) {
        if (obj instanceof Animal) {
            Animal objAsAnimal = (Animal) obj;
            if (objAsAnimal.getName().equals(this.name) && objAsAnimal.getColor().equals(this.color) && objAsAnimal.getAge() == this.age)
                return true;
        }
        return false;
    }
}

class Cat extends Animal {
    int numberOfWhiskers;

    public Cat(String name, String color, int age, int numberOfWhiskers) {
        super(name, color, age);
        setNumberOfWhiskers(numberOfWhiskers);
    }

    public int getNumberOfWhiskers() {
        return numberOfWhiskers;
    }

    public void setNumberOfWhiskers(int numberOfWhiskers) {
        if (numberOfWhiskers > 0 && numberOfWhiskers < 50) {
            this.numberOfWhiskers = numberOfWhiskers;
        } else throw new IllegalArgumentException("Number of whiskers must be between 1 and 50");

    }

    public String toString() {
        return super.toString() + ", number of whiskers=" + numberOfWhiskers;
    }

    public boolean equals(Object obj) {
        if (obj instanceof Cat) {
            Cat objAsCat = (Cat) obj;
            if (super.equals(obj) && objAsCat.getNumberOfWhiskers() == this.numberOfWhiskers)
                return true;
        }
        return false;
    }
}

class Hedgehog extends Animal {
    int numberOfNeedles;

    public Hedgehog(String name, String color, int age, int numberOfNeedles) {
        super(name, color, age);
        setNumberOfNeedles(numberOfNeedles);
    }

    public int getNumberOfNeedles() {
        return numberOfNeedles;
    }

    public void setNumberOfNeedles(int numberOfNeedles) {
        if (numberOfNeedles > 0 && numberOfNeedles < 50) {
            this.numberOfNeedles = numberOfNeedles;
        } else throw new IllegalArgumentException("Number of needles must be between 1 and 50");
    }

    public String toString() {
        return super.toString() + ", number of needles=" + numberOfNeedles;
    }

    public boolean equals(Object obj) {
        if (obj instanceof Hedgehog) {
            Hedgehog objAsHedgehog = (Hedgehog) obj;
            if(super.equals(obj) && objAsHedgehog.getNumberOfNeedles() == this.numberOfNeedles)
                return true;
        }
        return false;
    }
}

class Snake extends Animal {
    int length;

    public Snake(String name, String color, int age, int length) {
        super(name, color, age);
        setLength(length);
    }

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        if (length > 0 && length < 250) {
            this.length = length;
        } else throw new IllegalArgumentException("Length must be between 1 and 250");
    }

    public String toString() {
        return super.toString() + ", length=" + length;
    }

    public boolean equals(Object obj) {
        if (obj instanceof Snake) {
            Snake objAsSnake = (Snake) obj;
            if(super.equals(obj) && objAsSnake.getLength() == this.length)
                return true;
        }
        return false;
    }
}

class Main {

    public static void main(String[] args) {
        Animal testAnimal = new Animal("luna", "grey", 2);
        Cat testCat = new Cat("Muscat", "red", 7, 30);
        Hedgehog testHedgehod = new Hedgehog("Moon", "yellow", 1, 40);
        Cat testCat2 = new Cat("Muscat", "red", 7, 30);
        Cat testCat3 = new Cat("Muscat", "yellow", 7, 30);
        System.out.println(testAnimal + "\n" + testHedgehod + "\n" + testCat);
        System.out.println(testCat.equals(testCat2) + "\n" + testCat.equals(testAnimal) + "\n" + testCat.equals(testCat3));
    }
}

