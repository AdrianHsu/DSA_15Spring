CC=g++
FNAME=a1a.train
PNAME=a1a.train
EPSILON=0
T=50
RM=rm -rf

.PHONY: clean_tree_pred_func clean_forest_pred_func run_tree run_forest predict_tree predict_forest clean

4_1: tree run_decision_tree run_tree
4_2: forest run_decision_forest run_forest

tree: tree.cpp
	$(CC) tree.cpp -o $@
run_decision_tree:
	./tree $(FNAME) $(EPSILON) > tree_pred_func.cpp
run_decision_forest:
	./forest $(FNAME) $(T) > forest_pred_func.cpp


#tree_pred_func.cpp: tree $(FNAME)
#	./tree $(FNAME) $(EPSILON) > $@

clean_tree_pred_func: 
	$(RM) tree_pred_func.cpp
                      
#forest_pred_func.cpp: forest $(FNAME)
#	./forest $(FNAME) $(T) > $@

clean_forest_pred_func: 
	$(RM) forest_pred_func.cpp

predict_tree: tree_predictor.cpp tree_pred_func.cpp
	$(CC) tree_predictor.cpp tree_pred_func.cpp -o tree_predictor
	./tree_predictor $(PNAME) > ./tree_prediction.txt

#run_tree: predict_tree clean_tree_pred_func
run_tree: predict_tree

predict_forest: forest_predictor.cpp forest_pred_func.cpp $(PNAME)
	$(CC) forest_predictor.cpp forest_pred_func.cpp -o forest_predictor
	./forest_predictor $(PNAME) > ./forest_prediction.txt

#run_forest: clean_forest_pred_func predict_forest
run_forest: predict_forest
clean:
	$(RM) tree_predictor forest_predictor tree_pred_func.cpp forest_pred_func.cpp
