<?php

namespace Component\Collection;

use Component\Domain\Devis;

class DevisCollection
{
    private array $devis;

    public function addDevis(Devis $devis): void
    {
        $this->devis[] = $devis;
    }

    public function getDevis(): array
    {
        return $this->devis;
    }

    public function get(int $index): ?Devis
    {
        return $this->devis[$index] ?? null;
    }

    public function count(): int
    {
        return count($this->devis);
    }
}