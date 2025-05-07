<?php

namespace Infrastructure\Builder;

interface ProductBuilderInterface
{
    /**
     * @param array<array<string, mixed>> $rawProductData
     */
    public function createFrom(array $rawProductData): self;

    public function filter(callable $filterFn): self;

    public function getCollection(): iterable;
}
