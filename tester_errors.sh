#!/bin/bash

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

# Cores
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
NC='\033[0m'

echo -e "${CYAN}╔════════════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║${NC}        TESTER DE ERROS E CÓDIGOS DE RETORNO - PUSH_SWAP${NC}                  ${CYAN}║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════════════╝${NC}"

PASS_COUNT=0
FAIL_COUNT=0

# ============================================================================
# TESTES DE RETORNO 0 (Sem erro)
# ============================================================================

echo -e "\n${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}✅ TESTES DE RETORNO 0 (Sucesso esperado)${NC}"
echo -e "${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

# Teste 1: Sem argumentos
echo -e "\n${YELLOW}Teste 1: Sem argumentos${NC}"
$PUSH_SWAP 2>/dev/null
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP (sem args)"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -eq 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (retorno 0 esperado)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (esperava 0, recebeu $RETVAL)"
    ((FAIL_COUNT++))
fi

# Teste 2: Um elemento
echo -e "\n${YELLOW}Teste 2: Um elemento${NC}"
$PUSH_SWAP 42 > /dev/null 2>&1
RETVAL=$?
OUTPUT=$($PUSH_SWAP 42 2>/dev/null)
echo -e "   Comando: \$PUSH_SWAP 42"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
echo -e "   Output: ${CYAN}'$OUTPUT'${NC}"
if [ $RETVAL -eq 0 ] && [ -z "$OUTPUT" ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (retorno 0, sem output)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC}"
    ((FAIL_COUNT++))
fi

# Teste 3: Dois ordenados
echo -e "\n${YELLOW}Teste 3: Dois ordenados (1 2)${NC}"
$PUSH_SWAP 1 2 > /dev/null 2>&1
RETVAL=$?
OUTPUT=$($PUSH_SWAP 1 2 2>/dev/null)
CHECK=$($PUSH_SWAP 1 2 2>/dev/null | $CHECKER 1 2 2>&1)
echo -e "   Comando: \$PUSH_SWAP 1 2"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
echo -e "   Checker: ${CYAN}$CHECK${NC}"
if [ $RETVAL -eq 0 ] && [ "$CHECK" = "OK" ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC}"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC}"
    ((FAIL_COUNT++))
fi

# ============================================================================
# TESTES DE ERRO (Retorno != 0)
# ============================================================================

echo -e "\n${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}❌ TESTES DE ERRO (Retorno != 0 esperado)${NC}"
echo -e "${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

# Teste 4: Duplicados
echo -e "\n${YELLOW}Teste 4: Números duplicados (1 2 3 2 4)${NC}"
$PUSH_SWAP 1 2 3 2 4 > /dev/null 2>&1
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP 1 2 3 2 4"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -ne 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (erro detectado: $RETVAL)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (deveria retornar erro)"
    ((FAIL_COUNT++))
fi

# Teste 5: Não-numérico
echo -e "\n${YELLOW}Teste 5: Argumento não-numérico (1 2 abc)${NC}"
$PUSH_SWAP 1 2 abc > /dev/null 2>&1
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP 1 2 abc"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -ne 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (erro detectado: $RETVAL)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (deveria retornar erro)"
    ((FAIL_COUNT++))
fi

# Teste 6: Overflow
echo -e "\n${YELLOW}Teste 6: Overflow INT_MAX (2147483648)${NC}"
$PUSH_SWAP 2147483648 > /dev/null 2>&1
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP 2147483648"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -ne 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (overflow detectado: $RETVAL)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (deveria retornar erro)"
    ((FAIL_COUNT++))
fi

# Teste 7: Underflow
echo -e "\n${YELLOW}Teste 7: Underflow INT_MIN (-2147483649)${NC}"
$PUSH_SWAP -2147483649 > /dev/null 2>&1
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP -2147483649"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -ne 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (underflow detectado: $RETVAL)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (deveria retornar erro)"
    ((FAIL_COUNT++))
fi

# Teste 8: Caracteres especiais
echo -e "\n${YELLOW}Teste 8: Caracteres especiais (1 2 @)${NC}"
$PUSH_SWAP 1 2 @ > /dev/null 2>&1
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP 1 2 @"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -ne 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (erro detectado: $RETVAL)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (deveria retornar erro)"
    ((FAIL_COUNT++))
fi

# Teste 9: Argumento vazio
echo -e "\n${YELLOW}Teste 9: Argumento vazio ('')${NC}"
$PUSH_SWAP "" > /dev/null 2>&1
RETVAL=$?
echo -e "   Comando: \$PUSH_SWAP ''"
echo -e "   Retorno: ${CYAN}$RETVAL${NC}"
if [ $RETVAL -ne 0 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC} (erro detectado: $RETVAL)"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC} (deveria retornar erro)"
    ((FAIL_COUNT++))
fi

# ============================================================================
# RESUMO FINAL
# ============================================================================

echo -e "\n${CYAN}╔════════════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║${NC}                    RESUMO DE ERROS E RETORNOS${NC}                            ${CYAN}║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════════════╝${NC}"

TOTAL=$((PASS_COUNT + FAIL_COUNT))
PERCENTAGE=$((PASS_COUNT * 100 / TOTAL))

echo -e "\n${BLUE}Testes Executados: ${CYAN}$TOTAL${NC}"
echo -e "${GREEN}Testes Passou: ${CYAN}$PASS_COUNT${NC}"
echo -e "${RED}Testes Falharam: ${CYAN}$FAIL_COUNT${NC}"
echo -e "${MAGENTA}Taxa de Sucesso: ${CYAN}$PERCENTAGE%${NC}"

echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

if [ $FAIL_COUNT -eq 0 ]; then
    echo -e "${GREEN}✅ TODOS OS TESTES DE ERRO PASSARAM!${NC}"
else
    echo -e "${YELLOW}⚠️  $FAIL_COUNT testes com problemas${NC}"
fi

echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}\n"
