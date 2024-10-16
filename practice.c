#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printStars() {
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf(" imagine, these as stars./n");
}

typedef struct {
    char *explanation;
    char *problems[10]; // Adjust size based on the number of problems
    char *answers[10]; // Store correct answers
    int numProblems;
    char *topicName;
} Topic;

void initializeTopics(Topic *topics) {
    // Topic 1: Sentence Structure

    clearScreen();
    topics[0] = (Topic) {
        .explanation = "\n\nThis Program was created by Atif Ahnaf Chowdhury. \nFor Nayon sir,\n"
                       "Sir, jei topic e issue dekhabe, oi topic ta amake diyen, ami pdf pathay dibone\n"
                       "Instructions, 1. shob small letter e answer diben.\n"
                       "              2. stars ashle, bujhben apnar answer 80 percent accurate. congrats.\n"
                       "              3. ei program auto cholbe, so wait.\nLet's begin...\n  "
                       "\n\n### Topic 1: Sentence Structure\n"
                       "Sentence structure refers to the arrangement of words and phrases to create meaningful sentences. "
                       "Understanding sentence structure is crucial for effective communication.\n"
                       "\n\nTypes of Sentences:\n"
                       "1. Simple sentences: Contain one independent clause.\n"
                       "   Example: \"The cat sat on the mat.\"\n"
                       "2. Compound sentences: Contain two or more independent clauses joined by a coordinating conjunction.\n"
                       "   Example: \"The cat sat on the mat, and the dog lay on the floor.\"\n"
                       "3. Complex sentences: Contain one independent clause and at least one dependent clause.\n"
                       "   Example: \"Although the cat sat on the mat, the dog remained outside.\"\n"
                       "\n\nAdditionally, be aware of:\n"
                       "4. Sentence fragments: Incomplete sentences that lack an independent clause.\n"
                       "   Example: \"When we went to the store.\"\n"
                       "5. Run-on sentences: Two or more independent clauses joined improperly.\n"
                       "   Example: \"I like to swim I go to the pool every day.\"\n"
                       "6. Parallel structure: Using the same pattern of words for clarity in lists.\n"
                       "   Example: \"I enjoy hiking, swimming, and biking.\"\n",
        .problems = {
            "1. The cat sat on the mat and the dog lay on the floor. (simple, compound, complex)",
            "2. Although it rained we still went for a walk. (simple, compound, complex)",
            "3. I skipped Because I was tired. (simple, compound, complex)",
            "4. I like to read I also enjoy writing. (simple, compound, complex)",
            "5. She likes running, to swim, and biking. (correct/incorrect)\n\n",
        },
        .answers = {"compound", "complex", "complex", "compound", "incorrect"},
        .numProblems = 5,
        .topicName = "Sentence Structure"
    };

    // Topic 2: Subject-Verb Agreement
    topics[1] = (Topic) {
        .explanation = "\n\n### Topic 2: Subject-Verb Agreement\n"
                       "Subject-verb agreement refers to the grammatical rule that the subject and verb in a sentence must agree in number (singular or plural). "
                       "This ensures clarity in communication.\n"
                       "\n\nKey Points:\n"
                       "1. A singular subject takes a singular verb, while a plural subject takes a plural verb.\n"
                       "   Example: \"The cat runs.\" (singular) vs. \"The cats run.\" (plural)\n"
                       "2. Indefinite pronouns (everyone, someone) are considered singular.\n"
                       "   Example: \"Everyone is invited.\"\n"
                       "3. Collective nouns (team, group) can be singular or plural depending on context.\n"
                       "   Example: \"The team wins.\" vs. \"The team are wearing their uniforms.\"\n\n",
        .problems = {
            "1. The team are winning the match. (y/n)",
            "2. Everyone have finished their homework. (y/n)",
            "3. The dogs barks loudly. (y/n)",
            "4. Each of the students are responsible for their own work. (y/n)\n\n",
        },
        .answers = {"n", "n", "n", "n"},
        .numProblems = 4,
        .topicName = "Subject-Verb Agreement"
    };

    // Topic 3: Tense Consistency
    topics[2] = (Topic) {
        .explanation = "\n\n### Topic 3: Tense Consistency\n"
                       "Tense consistency refers to maintaining the same tense throughout a sentence or paragraph. "
                       "Mixing tenses can confuse the reader.\n"
                       "\n\nKey Points:\n"
                       "1. Present, past, and future tenses must be used appropriately.\n"
                       "   Example: \"I walk to school every day.\" (present)\n"
                       "2. Perfect and progressive aspects indicate ongoing actions or actions completed before another action.\n"
                       "   Example: \"I have been studying for two hours.\" (perfect progressive)\n"
                       "3. Avoid shifting tenses within a sentence or paragraph unless indicating a change in time.\n\n",
        .problems = {
            "1. I was walking to the store and I see my friend. (consistent/inconsistent)",
            "2. She will go to the party yesterday. (consistent/inconsistent)",
            "3. They have finished their homework and they are playing outside. (consistent/inconsistent)",
            "4. I eat breakfast before I went to work. (consistent/inconsistent)\n\n",
        },
        .answers = {"inconsistent", "inconsistent", "consistent", "inconsistent"},
        .numProblems = 4,
        .topicName = "Tense Consistency"
    };

    // Topic 4: Articles and Determiners
    topics[3] = (Topic) {
        .explanation = "\n\n### Topic 4: Articles and Determiners\n"
                       "Articles and determiners help specify nouns and provide clarity in sentences.\n"
                       "\n\nKey Points:\n"
                       "1. Definite and indefinite articles (a, an, the) indicate specificity.\n"
                       "   Example: \"A cat\" (any cat) vs. \"The cat\" (a specific cat).\n"
                       "2. Zero article usage refers to the absence of an article when speaking generally.\n"
                       "   Example: \"Cats are great pets.\"\n"
                       "3. Quantifiers (some, any, much, many, etc.) indicate quantity.\n"
                       "   Example: \"I have some apples.\"\n\n",
        .problems = {
            "1. I saw a elephant at the zoo. (correct/incorrect)",
            "2. The cats are playing in the garden. (correct/incorrect)",
            "3. We need much water for the trip. (correct/incorrect)",
            "4. I have some friends coming over. (correct/incorrect)\n\n",
        },
        .answers = {"incorrect", "correct", "incorrect", "correct"},
        .numProblems = 4,
        .topicName = "Articles and Determiners"
    };

    // Topic 5: Prepositions
    topics[4] = (Topic) {
        .explanation = "\n\n### Topic 5: Prepositions\n"
                       "Prepositions show relationships between nouns and other words in a sentence.\n"
                       "\n\nKey Points:\n"
                       "1. Common prepositions of time (at, in, on), place (above, below, between), and direction (to, from, into).\n"
                       "   Example: \"She arrived at 5 PM.\"\n"
                       "2. Prepositional phrases consist of a preposition and its object.\n"
                       "   Example: \"In the morning, we will leave.\"\n"
                       "3. Preposition usage with verbs and adjectives can change the meaning of sentences.\n"
                       "   Example: \"She is interested in art.\"\n\n",
        .problems = {
            "1. The book is on the table. (correct/incorrect)",
            "2. He walked to the store yesterday. (correct/incorrect)",
            "3. She is good in math. (correct/incorrect)",
            "4. They will meet at the park. (correct/incorrect)\n\n",
        },
        .answers = {"correct", "correct", "incorrect", "correct"},
        .numProblems = 4,
        .topicName = "Prepositions"
    };

    // Topic 6: Punctuation
    topics[5] = (Topic) {
        .explanation = "\n\n### Topic 6: Punctuation\n"
                       "Punctuation marks help clarify meaning and separate ideas in writing.\n"
                       "\n\nKey Points:\n"
                       "1. Comma usage includes separating items in a list and after introductory clauses.\n"
                       "   Example: \"I bought apples, oranges, and bananas.\"\n"
                       "2. Semicolons connect closely related independent clauses.\n"
                       "   Example: \"I like tea; she prefers coffee.\"\n"
                       "3. Quotation marks are used to denote direct speech, while apostrophes indicate possession.\n"
                       "   Example: \"He said, 'It's John's book.'\"",
        .problems = {
            "\n\n1. I need to buy milk eggs and bread. (correct/incorrect)",
            "2. She said, I am coming. (correct/incorrect)",
            "3. He likes ice cream; she likes cake. (correct/incorrect)",
            "4. Its a nice day. (correct/incorrect)",
        },
        .answers = {"incorrect", "incorrect", "correct", "incorrect"},
        .numProblems = 4,
        .topicName = "Punctuation"
    };

    // Topic 7: Pronouns
    topics[6] = (Topic) {
        .explanation = "\n\n### Topic 7: Pronouns\n"
                       "Pronouns replace nouns to avoid repetition and simplify sentences.\n"
                       "\n\nKey Points:\n"
                       "1. Personal pronouns (he, she, it) refer to specific people or things.\n"
                       "2. Possessive pronouns (my, your, their) indicate ownership.\n"
                       "3. Reflexive pronouns (myself, yourself) refer back to the subject.\n"
                       "4. Relative pronouns (who, which, that) introduce relative clauses.\n"
                       "   Example: \"The book that I read was interesting.\"\n\n",
        .problems = {
            "1. Everyone should take care of their health. (correct/incorrect)",
            "2. Each student must submit their homework on time. (correct/incorrect)",
            "3. Her and I went to the movies. (correct/incorrect)",
            "4. The dog chased it's tail. (correct/incorrect)\n\n",
        },
        .answers = {"correct", "correct", "incorrect", "incorrect"},
        .numProblems = 4,
        .topicName = "Pronouns"
    };

    // Topic 8: Adjectives and Adverbs
    topics[7] = (Topic) {
        .explanation = "\n\n### Topic 8: Adjectives and Adverbs\n"
                       "Adjectives and adverbs modify nouns and verbs, respectively, adding detail to sentences.\n"
                       "\n\nKey Points:\n"
                       "1. Comparative and superlative forms compare two or more items.\n"
                       "   Example: \"She is taller than her brother.\" (comparative)\n"
                       "   Example: \"She is the tallest in the class.\" (superlative)\n"
                       "2. Placement of adjectives typically comes before the noun they modify, while adverbs can modify verbs, adjectives, or other adverbs.\n"
                       "   Example: \"The quick brown fox jumps swiftly.\"\n"
                       "3. Differentiating between adjectives and adverbs is important for clarity.\n\n",
        .problems = {
            "1. She runs quick. (correct/incorrect)",
            "2. He is the best player on the team. (correct/incorrect)",
            "3. This cake is more delicious than that one. (correct/incorrect)",
            "4. She sings beautiful. (correct/incorrect)",
        },
        .answers = {"incorrect", "correct", "correct", "incorrect"},
        .numProblems = 4,
        .topicName = "Adjectives and Adverbs"
    };

    // Topic 9: Active and Passive Voice
    topics[8] = (Topic) {
        .explanation = "\n\n### Topic 9: Active and Passive Voice\n"
                       "Voice indicates the relationship between the action of the verb and the participants in the sentence.\n"
                       "\n\nKey Points:\n"
                       "1. In active voice, the subject performs the action of the verb.\n"
                       "   Example: \"The chef cooked the meal.\"\n"
                       "2. In passive voice, the subject receives the action of the verb.\n"
                       "   Example: \"The meal was cooked by the chef.\"\n"
                       "3. Use passive voice appropriately, often when the doer is unknown or irrelevant.\n",
        .problems = {
            "\n1. The ball was thrown by the child. (active/passive)",
            "2. The teacher explained the lesson. (active/passive)",
            "3. The cookies were baked by my grandmother. (active/passive)",
            "4. The song sang beautifully. (active/passive)",
        },
        .answers = {"passive", "active", "passive", "incorrect"},
        .numProblems = 4,
        .topicName = "Active and Passive Voice"
    };

    // Topic 10: Modifiers
    topics[9] = (Topic) {
        .explanation = "### Topic 10: Modifiers\n"
                       "Modifiers add detail to sentences but can create confusion if misplaced.\n"
                       "\n\nKey Points:\n"
                       "1. Misplaced modifiers can lead to unclear meaning.\n"
                       "   Example: \"She almost drove her kids to school every day.\" (implies she didn't often drive them)\n"
                       "2. Dangling modifiers lack a clear subject.\n"
                       "   Example: \"After reading the book, the movie was disappointing.\" (who read the book?)\n"
                       "3. Correct placement of modifiers is essential for clarity.\n",
        .problems = {
            "\n1. The dog barked loudly at the man in the park. (correct/incorrect)",
            "2. Running fast, the finish line was crossed by John. (correct/incorrect)",
            "3. She almost won the race with a broken leg. (correct/incorrect)",
            "4. Covered in chocolate, I ate the strawberries. (correct/incorrect)",
        },
        .answers = {"correct", "incorrect", "incorrect", "incorrect"},
        .numProblems = 4,
        .topicName = "Modifiers"
    };
}

void interactiveTopic(Topic topic) {
    char userAnswers[10][20]; // Adjust size based on the number of questions
    int wrongAttempts = 0;

    printf("%s\n", topic.explanation);

    // Prompt to press enter before displaying problems
    printf("Press 'Enter' to see the problem set...");
    getchar(); // Wait for user to press enter

    for (int i = 0; i < topic.numProblems; i++) {
        printf("%s\n", topic.problems[i]);
        printf("Please enter your answer: ");
        scanf(" %s", userAnswers[i]);

        // Check answer
        if (strcmp(userAnswers[i], topic.answers[i]) == 0) {
            wrongAttempts = 0; // Reset wrong attempts
        } else {
            wrongAttempts++;
            printf("Incorrect! Try again.\n");
            if (wrongAttempts == 3) {
                clearScreen();
                printf("SIR, APNAR %s TOPIC E PROBLEM.\n", topic.topicName);
                printf("Questions:\n");
                for (int j = 0; j < topic.numProblems; j++) {
                    printf("%s\n", topic.problems[j]);
                }
                printf("Answers:\n");
                for (int j = 0; j < topic.numProblems; j++) {
                    printf("%s\n", topic.answers[j]);
                }
                return; // Exit this topic on 3 wrong attempts
            }
            i--; // Repeat the current question
        }
    }

    printf("SHERA! Let's proceed to the next topic.\n");
    clearScreen();
    printStars();
    sleep(2); // Wait for 2 seconds
    clearScreen();
}

int main() {
    Topic topics[10]; // Adjust size based on the number of topics
    initializeTopics(topics);

    // Run through each topic
    for (int i = 0; i < 10; i++) { // Loop through all topics
        interactiveTopic(topics[i]);
    }

    return 0;
}