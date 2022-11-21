#include "validateProgram.h"

/**
 * Implementación de "validateProgram.h".
 */

boolean validateProgram(Program * program){
	if(program == NULL){
        return false;
    } else {
        if(program->graph->type == WITH_POOL){
            return validatePool(program->graph->pool);
        } 
        if(program->graph != NULL){
            return validateCreate(program->graph->create);
        }
    }
    return false;
}

boolean validatePool(Pool * pool){
    if(pool->createP != NULL){
        return validateCreateP(pool->createP);
    }
    if(pool->lane != NULL){
        return validateLane(pool->lane);
    }
    if(pool->next){
       return validatePool(pool->next);
    }
    return false;
}

boolean validateCreate(Create *  create){
    if(create->next != NULL){
		return validateCreate(create->next);
	}
    if(create->expression != NULL){
		return validateExpression(create->expression);
	}
    return false;
}

boolean validateExpression(Expression *  expression){
    if(expression->exp == CONNECT_EXP){
		return validateConnection(expression->connect);
	}
    return true;
}

boolean validateConnection(Connect * connect){
	if( existInTable(state.table, connect->from) == true){
        if(existInTable(state.table, connect->to) == true){
            return true;
        }else{
            LogError("Conexión inválida, variable %s no existente", connect->to);
            return false;
        }
    }else{
        LogError("Conexión inválida, variable %s no existente", connect->from);
        return false;
    } 
}
 
boolean validateGateway(Gateway * gateway){
    if(gateway->set != NULL){
        return validateSet(gateway->set);
    }
    return false;
}

boolean validateCreateP(CreateP * createP){
    if(createP->create != NULL){
        return validateCreate(createP->create);
    }
    return false;
}

boolean validateLane(Lane * lane){
    if(lane->create != NULL){
        return validateCreate(lane->create);
    }
    if(lane->next != NULL){
        return validateLane(lane->next);
    }
    return false;
}

boolean validateSet(Set * set){
    if(set->connect != NULL){
        return (existInTable(state.table, set->connect->to) == true);
    }
    if(set->next != NULL){
        return validateSet(set->next);
    }
    return false;
}