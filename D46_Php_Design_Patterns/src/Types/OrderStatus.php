<?php

namespace Types;

enum OrderStatus
{
    case VALIDATE;
    case IN_PROCESS;
    case IN_TRANSFERT;
    case RECEIVED;
}
