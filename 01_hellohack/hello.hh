<?hh // strict

class Hello {

    // a special way of initializing class members
    public function __construct(
        private string $_hello = 'hack'
    ) : void {}

    public function setHello(string $hello) : this {
        $this->_hello = $hello;
        return $this;
    }

    public function getHello() : string {
        return 'Hello, ' . $this->_hello . '!';
    }

    public function __toString() : string {
        return $this->getHello();
    }

}

$helloThing = new Hello();

echo $helloThing->getHello() . PHP_EOL;

echo $helloThing->setHello('world') . PHP_EOL;

echo new Hello('foobar') . PHP_EOL;
