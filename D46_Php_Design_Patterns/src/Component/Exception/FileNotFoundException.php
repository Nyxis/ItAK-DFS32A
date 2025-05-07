<?php

class FileNotFoundException extends RuntimeException
{
    public function __construct(string $message = "Ce fichier n'a pas été trouvée", int $code = 0, ?Throwable $previous = null)
    {
        parent::__construct($message, $code, $previous);
    }
}