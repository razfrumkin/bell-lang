#pragma once

#include <vector>

#include "string_info.hpp"

struct Statement;
struct Expression;

struct Type {
    StringInfo type_name;

    Type() = default;
    Type(const StringInfo& type_name) :
        type_name(type_name) {}
};

struct Parameter {
    StringInfo identifier;
    Type type;

    Parameter() = default;
    Parameter(const StringInfo& identifier, const Type& type) :
        identifier(identifier),
        type(type)
    {}
};

struct Procedure {
    StringInfo identifier;
    std::vector<Parameter> parameters;
    Type return_value;
    std::vector<Statement> statements;

    Procedure() = default;
    Procedure(const StringInfo& identifier, const std::vector<Parameter>& parameters, const Type& return_value, const std::vector<Statement>& statements) :
        identifier(identifier),
        parameters(parameters),
        return_value(return_value),
        statements(statements) {}
};

struct Expression {

};

struct IntegerLiteral : Expression {
    StringInfo value;

    IntegerLiteral() = default;
    IntegerLiteral(const StringInfo& value) :
        value(value) {}
};

enum Operator {
    Plus,
    Minus,
    Multiply,
    Divide
};

struct BinaryOperation : Expression {
    Expression left;
    Operator op;
    Expression right;

    BinaryOperation() = default;
    BinaryOperation(const Expression& left, const Operator op, const Expression& right) :
        left(left),
        op(op),
        right(right) {}
};

struct Call : Expression {
    StringInfo identifier;
    std::vector<Expression> parameters;

    Call() = default;
    Call(const StringInfo& identifier, const std::vector<Expression>& parameters) :
        identifier(identifier),
        parameters(parameters) {}
};

struct Statement {

};

struct ReturnStatement : public Statement {
    Expression expression;

    ReturnStatement() = default;
    ReturnStatement(const Expression& expression) :
        expression(expression) {}
};