<?php

namespace Component;

class Service extends Product
{
    private string $mission;
    private int $duree;

    public function __construct(string $ean, string $mission, int $duree)
    {
        parent::__construct($ean, $mission);
        $this->mission = $mission;
        $this->duree = $duree;
    }

    public function getMission(): string
    {
        return $this->mission;
    }

    public function getDuree(): int
    {
        return $this->duree;
    }
}
