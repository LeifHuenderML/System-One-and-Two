rm -rf build
python3 setup.py clean --all
python3 setup.py build_ext --inplace
pip uninstall andrea -y
pip install -e .