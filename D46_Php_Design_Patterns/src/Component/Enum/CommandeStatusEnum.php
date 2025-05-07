<?php

namespace Component\Enum;

enum CommandeStatusEnum: string
{
    case PENDING = 'En attente';
    case DELIVERED = 'Livrée';
    case CANCELLED = 'Anuller';
}
