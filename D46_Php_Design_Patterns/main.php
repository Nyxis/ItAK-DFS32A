<?php

$maVar = 1;               // scalar : int|float|bool|string

$f = fn($a, $b) => {};      // callable

$obj = new \stdClass();   // pas de type général

function (int|float $a, float $b, \stdClass $c, \Closure $fn)

new Object(/*......, */ function ($a, $b) use ($maVar) {
    $this
});

$product->sku;


json_decode(
    json: '....',
    associative: true,
    flags: ENT_COMPAT
);


class ProductSqlFactory
{
    const string END = 'end';

    /** ......... */

    public function query(string $sql)
    {
        $result = mysql_query($sql);

        while(mysql_fetch_assoc($result)) {
            if (self::END == yield) {
                fclose(/* .... */);
                break;
            }

            yield new Product(
                .......
            );
        }
    }
}

$result = $factory->query('select * from products');

try {
    foreach ($result as $product) {
        // .......

        if ($status != SUCCESS) {
            throw new \Exception();
        }
    }
}
catch (\Exception $e) {
    .....
    $result->throw($e);
}
finally {
}

enum StockStatus
{
    case OUT_OF_STOCK;
    case IN_STOCK;
    case REASSORT;
}

class Product implements \Stringable
{
    private bool $isAvailable;

    public function __construct(
        readonly public string $sku,
        private Stock $stock
    ) {
        $this->isAvailable = $this->stock->getStatus() != StockStatus::OUT_OF_STOCK ;
    }

    public function isAvaiblable() : bool
    {
        return $this->isAvailable;
    }

    public function markAsAvailable(StockStatus $status)
    {

    }

    public function render() : string
    {
        return $this->sku;
    }

    public function __toString() : string
    {
        return $this->render();
    }
}
