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
echo -e "${CYAN}║${NC}     TESTER DETALHADO - ESCALA DE AVALIAÇÃO 42 PUSH_SWAP${NC}                 ${CYAN}║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════════════╝${NC}"

PASS_COUNT=0
FAIL_COUNT=0

# ============================================================================
# CRITÉRIO 1: 3 ELEMENTOS
# ============================================================================

echo -e "\n${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}📋 CRITÉRIO 1: 3 ELEMENTOS (máx 3 operações)${NC}"
echo -e "${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

ARG="3 1 2"
OPS=$($PUSH_SWAP $ARG 2>/dev/null | wc -l)
CHECK=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>&1)

echo -e "\n${YELLOW}Teste 1:${NC} ARG='$ARG'"
echo -e "   Operações: ${CYAN}$OPS${NC} | Limite: 3"
echo -e "   Checker: ${CYAN}$CHECK${NC}"

if [ "$CHECK" = "OK" ] && [ $OPS -le 3 ]; then
    echo -e "   ${GREEN}✅ PASSOU${NC}"
    ((PASS_COUNT++))
else
    echo -e "   ${RED}❌ FALHOU${NC}"
    ((FAIL_COUNT++))
fi

# ============================================================================
# CRITÉRIO 2: 5 ELEMENTOS
# ============================================================================

echo -e "\n${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}📋 CRITÉRIO 2: 5 ELEMENTOS (máx 12 operações)${NC}"
echo -e "${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

for i in {1..3}; do
    ARG=$(python3 -c "import random; random.seed($((42+i))); nums = list(range(1, 6)); random.shuffle(nums); print(' '.join(map(str, nums)))")
    OPS=$($PUSH_SWAP $ARG 2>/dev/null | wc -l)
    CHECK=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>&1)
    
    echo -e "\n${YELLOW}Teste 2.$i:${NC} ARG='$ARG'"
    echo -e "   Operações: ${CYAN}$OPS${NC} | Limite: 12"
    echo -e "   Checker: ${CYAN}$CHECK${NC}"
    
    if [ "$CHECK" = "OK" ] && [ $OPS -le 12 ]; then
        echo -e "   ${GREEN}✅ PASSOU${NC}"
        ((PASS_COUNT++))
    else
        echo -e "   ${RED}❌ FALHOU${NC}"
        ((FAIL_COUNT++))
    fi
done

# ============================================================================
# CRITÉRIO 3: 100 ELEMENTOS (OBRIGATÓRIO ≤ 1100)
# ============================================================================

echo -e "\n${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}📋 CRITÉRIO 3: 100 ELEMENTOS (máx 1100 ops - OBRIGATÓRIO)${NC}"
echo -e "${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

TOTAL_OPS=0
for i in {1..5}; do
    ARG=$(python3 -c "import random; random.seed($((100+i))); nums = list(range(1, 101)); random.shuffle(nums); print(' '.join(map(str, nums)))")
    OPS=$($PUSH_SWAP $ARG 2>/dev/null | wc -l)
    CHECK=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>&1)
    TOTAL_OPS=$((TOTAL_OPS + OPS))
    
    echo -e "\n${YELLOW}Teste 3.$i:${NC}"
    echo -e "   Operações: ${CYAN}$OPS${NC} | Limite: 1100"
    echo -e "   Checker: ${CYAN}$CHECK${NC}"
    
    if [ "$CHECK" = "OK" ] && [ $OPS -le 1100 ]; then
        echo -e "   ${GREEN}✅ PASSOU${NC}"
        ((PASS_COUNT++))
    else
        echo -e "   ${RED}❌ FALHOU${NC}"
        ((FAIL_COUNT++))
    fi
done

AVG=$((TOTAL_OPS / 5))
echo -e "\n${BLUE}Resumo Critério 3: Média = ${CYAN}$AVG${BLUE} operações${NC}"

# ============================================================================
# CRITÉRIO 4: 500 ELEMENTOS (OBRIGATÓRIO ≤ 8500)
# ============================================================================

echo -e "\n${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}📋 CRITÉRIO 4: 500 ELEMENTOS (máx 8500 ops - OBRIGATÓRIO)${NC}"
echo -e "${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

TOTAL_OPS=0
for i in {1..3}; do
    ARG=$(python3 -c "import random; random.seed($((500+i))); nums = list(range(1, 501)); random.shuffle(nums); print(' '.join(map(str, nums)))")
    OPS=$($PUSH_SWAP $ARG 2>/dev/null | wc -l)
    CHECK=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>&1)
    TOTAL_OPS=$((TOTAL_OPS + OPS))
    
    echo -e "\n${YELLOW}Teste 4.$i:${NC}"
    echo -e "   Operações: ${CYAN}$OPS${NC} | Limite: 8500"
    echo -e "   Checker: ${CYAN}$CHECK${NC}"
    
    if [ "$CHECK" = "OK" ] && [ $OPS -le 8500 ]; then
        echo -e "   ${GREEN}✅ PASSOU${NC}"
        ((PASS_COUNT++))
    else
        echo -e "   ${RED}❌ FALHOU${NC}"
        ((FAIL_COUNT++))
    fi
done

AVG=$((TOTAL_OPS / 3))
echo -e "\n${BLUE}Resumo Critério 4: Média = ${CYAN}$AVG${BLUE} operações${NC}"

# ============================================================================
# RESUMO FINAL
# ============================================================================

echo -e "\n${CYAN}╔════════════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║${NC}                           RESUMO FINAL${NC}                                  ${CYAN}║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════════════╝${NC}"

TOTAL=$((PASS_COUNT + FAIL_COUNT))
PERCENTAGE=$((PASS_COUNT * 100 / TOTAL))

echo -e "\n${BLUE}Testes Executados: ${CYAN}$TOTAL${NC}"
echo -e "${GREEN}Testes Passou: ${CYAN}$PASS_COUNT${NC}"
echo -e "${RED}Testes Falharam: ${CYAN}$FAIL_COUNT${NC}"
echo -e "${MAGENTA}Taxa de Sucesso: ${CYAN}$PERCENTAGE%${NC}"

echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

if [ $FAIL_COUNT -eq 0 ]; then
    echo -e "${GREEN}✅ TODOS OS TESTES PASSARAM!${NC}"
    echo -e "${CYAN}Score Obrigatório: 80/80 pontos${NC}"
    echo -e "${YELLOW}TOTAL: 80/100 pontos ✅${NC}"
else
    echo -e "${RED}❌ ALGUNS TESTES FALHARAM - REVISAR!${NC}"
fi

echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}\n"
