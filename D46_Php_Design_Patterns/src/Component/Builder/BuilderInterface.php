<?php

namespace Component\Builder;

interface BuilderInterface {
    /**
     * Lire et extraire les données d'un fichier
     * @param string $filePath
     * @return array
     */
    public function parse(string $filePath): array;
}