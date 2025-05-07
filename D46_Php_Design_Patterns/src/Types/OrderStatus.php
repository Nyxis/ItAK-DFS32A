<?php

namespace Types;

enum OrderStatus
{
    case RECEIVED;
    case IN_PROCESS;
    case IN_TRANSFERT;
    case DELIVERED;
}