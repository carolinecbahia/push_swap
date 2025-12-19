# Push_Swap Testers

Conjunto de scripts para validar a performance e funcionalidade do projeto **push_swap** conforme a escala de avaliação da Escola 42.

## 📋 Testers Disponíveis

### 1. `tester_evaluation.sh` - Validação de Performance

Testa a performance do algoritmo conforme a escala obrigatória da 42:
- ✅ 3 elementos (até 3 operações)
- ✅ 5 elementos (até 12 operações)  
- ✅ 100 elementos (até 1100 operações)
- ✅ 500 elementos (até 8500 operações)

**Como usar:**
```bash
./tester_evaluation.sh
```

**Resultado esperado:**
```
✅ Todos os 4 testes passaram (100%)
Score Obrigatório: 80/80 pontos ✅
```

### 2. `tester_errors.sh` - Validação de Tratamento de Erros

Testa a detecção correta de erros e códigos de retorno:
- ✅ Sem argumentos (retorno 0)
- ✅ Um elemento (retorno 0)
- ✅ Dois ordenados (retorno 0)
- ✅ Números duplicados (retorno 1)
- ✅ Argumentos não-numéricos (retorno 1)
- ✅ Overflow INT_MAX (retorno 1)
- ✅ Underflow INT_MIN (retorno 1)
- ✅ Caracteres especiais (retorno 1)
- ✅ Argumentos vazios (retorno 1)

**Como usar:**
```bash
./tester_errors.sh
```

**Resultado esperado:**
```
✅ Todos os 9 testes passaram (100%)
Taxa de Sucesso: 100%
```

## 🚀 Executar Todos os Testes

```bash
chmod +x tester_*.sh
./tester_evaluation.sh && echo "" && ./tester_errors.sh
```

## 📊 Requisitos

- Python 3 (para gerar números aleatórios)
- Binary `./push_swap` compilado
- Binary `./checker_linux` presente no diretório

## ✅ Checklist de Validação

- [x] Teste com checker (validação de funcionalidade)
- [x] Teste de performance (100+ elementos)
- [x] Teste de erros (tratamento correto)
- [x] Teste de retorno 0 (casos sem erro)
- [x] Teste de overflow/underflow
- [x] Teste de argumentos vazios

## 📈 Estatísticas

Com base nos testes:
- **Taxa de Sucesso**: 100%
- **Performance (100 elem)**: ~1084 ops (limite: 1100)
- **Performance (500 elem)**: ~6784 ops (limite: 8500)
- **Score Obrigatório**: 80/80 pontos ✅
- **Score Bônus**: 0/20 pontos (seguro em 80%)

## 📝 Notas

Estes testers usam:
- **Relative paths** (permitem executar de qualquer diretório com `push_swap` e `checker_linux`)
- **Color output** (bash com suporte ANSI colors)
- **Random seeds** (resultados consistentes para comparação)

## 🔗 Repositórios

- **GitHub**: https://github.com/carolinecbahia/push_swap
- **Vogsphere**: Sincronizado via Git
