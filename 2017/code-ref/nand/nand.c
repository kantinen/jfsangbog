#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "nand.h"

static bit_t and(bit_t input0, bit_t input1) {
  return (input0 == jeps && input1 == jeps);
}

static bit_t not(bit_t input) {
  return (input == narj ? jeps : narj);
}

bit_t nand(bit_t input0, bit_t input1) {
  return not(and(input0, input1));
}

size_t get_free_output_ids(id_t* dest_free_output_ids,
                           nand_t* gates, size_t gates_length) {
  size_t outputs_length = gates_length;
  size_t inputs_length = gates_length * 2;
  size_t n_free_output_ids = 0;

  for (size_t i = 0; i < outputs_length; i++) {
    id_t output_id = gates[i].output_id;
    bool found = false;
    for (size_t j = 0; j < inputs_length; j++) {
      id_t input_id = gates[j / 2].input_ids[j % 2];
      if (input_id == output_id) {
        found = true;
        break;
      }
    }
    if (!found) {
      dest_free_output_ids[n_free_output_ids] = output_id;
      n_free_output_ids++;
    }
  }

  return n_free_output_ids;
}

bit_t evaluate_id(nand_t* gates, size_t gates_length,
                  size_t (*get_input)(size_t), id_t id) {
  for (size_t i = 0; i < gates_length; i++) {
    if (gates[i].output_id == id) {
      return nand(evaluate_id(gates, gates_length,
                              get_input, gates[i].input_ids[0]),
                  evaluate_id(gates, gates_length,
                              get_input, gates[i].input_ids[1]));
    }
  }
  return get_input(id);
}

void evaluate_outputs(nand_t* gates, size_t gates_length,
                      size_t (*get_input)(size_t), bit_t* outputs) {
  id_t* free_output_ids;
  size_t n_free_output_ids;
  
  free_output_ids = (id_t*) malloc(sizeof(id_t) * gates_length);
  n_free_output_ids = get_free_output_ids(free_output_ids,
                                          gates, gates_length);

  for (size_t i = 0; i < n_free_output_ids; i++) {
    bit_t output = evaluate_id(gates, gates_length,
                               get_input, free_output_ids[i]);
    outputs[i] = output;
  }
}

int main(int argc, char** argv) {

  return EXIT_SUCCESS;
}
