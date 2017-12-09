// Hver ledning har et unikt ID som er et positivt heltal.
typedef size_t id_t;

// Hver NAND-gate har to inputs og en output.
typedef struct {
  id_t input_ids[2];
  id_t output_id;
} nand_t;

// En bit kan enten være "narj" eller "jeps".
typedef enum {
  narj, // "0"
  jeps  // "1"
} bit_t;

// Beregn et NAND-udtryk og returnér dets resultat.
bit_t nand(bit_t input0, bit_t input1);

// Find alle frie `output_id'-værdier, dvs. værdier der *ikke* er inputs til
// gates.  `gates' er et sted i hukommelsen med `gates_length' elementer.  Skriv
// den sorterede liste af frie `output_id'-værdier til det præallokerede sted i
// hukommelsen `dest_free_output_ids' (garanteret til at have plads til mindst
// `gates_length' elementer), og returnér antallet af skrevne id'er.
size_t get_free_output_ids(id_t* dest_free_output_ids,
                           nand_t* gates, size_t gates_length);

// Find værdien for ledningen `id'.  `gates' og `gates_length' har samme
// betydning som i `get_free_output_ids'.  `get_input' er en funktionspeger som
// skal kaldes hvis en ledning ikke er output fra en gate, men i stedet er fri.
// Returnér den fundne værdi.
bit_t evaluate_id(nand_t* gates, size_t gates_length,
                  size_t (*get_input)(size_t), id_t id);

// Find værdierne for alle frie outputs.  Skriv dem til det præallokerede sted i
// hukommelsen `outputs' (garanteret til at have plads til mindst `gates_length'
// elementer).
void evaluate_outputs(nand_t* gates, size_t gates_length,
                      size_t (*get_input)(size_t), bit_t* outputs);
