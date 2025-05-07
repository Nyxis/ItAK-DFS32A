<?php

namespace Utils;
class Files
{
    public function getFile(string $url): string{
        return file_get_contents($url);
    }
}