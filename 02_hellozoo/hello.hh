<?hh // strict

newtype Animal = shape('name' => string, 'sound' => string);

class Hello {

    private Animal $animal;

    public function __construct(?Animal $animal = null) :void {
        if (null !== $animal) {
            $this->setAnimal($animal);
        }
        $this->setAnimal(shape('name' => 'human', 'sound' => 'hello'));
    }

    public function setAnimal(Animal $animal) : this {
        $this->_animal = $animal;
        return $this;
    }

    public function getHello() : string {
        return ucfirst($this->_animal['name']) . ': '
            . ucfirst($this->_animal['sound']) . ' world!';
    }

    public function __toString() : string {
        return $this->getHello();
    }

}

function test() : void {
    $animals = Map {
        'bird'    => 'tweet',
        'lion'    => 'roar',
        'sheep'   => 'baah',
        'pikachu' => 'pika',
    };

    $helloThing = new Hello();

    echo $helloThing . PHP_EOL;

    foreach ($animals as $name => $sound) {
        echo $helloThing->setAnimal(shape('name' => $name, 'sound' => $sound)) . PHP_EOL;
    }
}

test();
