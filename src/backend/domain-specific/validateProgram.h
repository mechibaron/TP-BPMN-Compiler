#ifndef VALIDATE_PROGRAM_HEADER
#define VALIDATE_PROGRAM_HEADER
#include "../semantic-analysis/abstract-syntax-tree.h"
#include "../support/shared.h"
#include "../support/logger.h"

boolean validateProgram(Program * program);
boolean validatePool(Pool * pool);
boolean validateCreate(Create *  create);
boolean validateCreateP(CreateP * createP);
boolean validateLane(Lane * lane);
boolean validateGateway(Gateway * gateway);
boolean validateExpression(Expression *  expression);
boolean validateConnection(Connect * connect);
boolean validateSet(Set * set);
#endif
