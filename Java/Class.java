public class Class {
    public static void main(String[] args) {
        Person harry = new Person("Harry", 12);
        harry.getName();
        // harry.getAge();
        harry.getData();
    }
}

class Person {
    String name;
    int age;
    Person(String constructorName, int constructorAge) {
        name = constructorName;
        age = constructorAge;
    }

    protected void getName() {
        System.out.println(name);
    }

    private void getAge() {
        System.out.println(age);
    }

    public void getData() {
        System.out.println("accessing get age: ");
        getAge();
        System.out.println("name: " + name + " age: " + age);
    }
}