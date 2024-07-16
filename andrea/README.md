rm -rf build
python3 setup.py clean --all
python3 setup.py build_ext --inplace
pip uninstall andrea -y
pip install -e .




pip uninstall andrea -y
rm -rf build dist *.egg-info
pip install -e . --use-pep517