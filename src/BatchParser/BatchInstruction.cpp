/*
Copyright (c) 2016, Klasa Sebastien
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
*  Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
*  Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
*  Neither the name of Klasa Sebastien nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY KLASA SEBASTIEN ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL KLASA SEBASTIEN BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "BatchInstruction.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

BatchInstruction::BatchInstruction() {
	this->text = "";
	this->command = "";
}

BatchInstruction::BatchInstruction(string const text)
	: BatchInstruction() {

	this->setText(text);
}

void BatchInstruction::parseText() {
	vector<string> vec = StrHelper::split(this->text, " ");
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = StrHelper::trim(vec[i]);
	}
	vector<string>::iterator it = vec.begin();
	do {
		if (*it == "")
			it = vec.erase(it);
		else
			it++;
	} while (it != vec.end());

	this->command = vec[0];

	vector<BatchArgument> arguments;

	int i = 1;
	while (i < vec.size()) {
		BatchArgument arg;

		if (vec[i][0] == '-' || vec[i][0] == '/') {
			arg.setName(vec[i]);
			i++;

			if (i < vec.size() && vec[i][0] != '-' && vec[i][0] != '/') {
				arg.setValue(vec[i]);
				i++;
			}
		}
		else {
			arg.setValue(vec[i]);
			i++;
		}

		arguments.push_back(arg);
	}

	this->arguments = arguments;
	this->generateText();
}

void BatchInstruction::generateText() {
	this->text = this->getCommand();
	for (int i = 0; i < this->argumentsCount(); i++) {
		BatchArgument cur_arg = this->arguments[i];

		if (cur_arg.getName() != "")
			this->text += " " + cur_arg.getName();
		if (cur_arg.getValue() != "") {
			if (cur_arg.getValue()[0] == '-' || cur_arg.getValue()[0] == '/')
				this->text += " \"" + cur_arg.getValue() + "\"";
			else
				this->text += " " + cur_arg.getValue();
		}
	}
}

string BatchInstruction::getText() const {
	return this->text;
}

void BatchInstruction::setText(string text) {
	this->text = StrHelper::trim(text);;
	this->parseText();
}

string BatchInstruction::getCommand() const {
	return this->command;
}

void BatchInstruction::setCommand(string command) {
	this->command = command;
	this->generateText();
}

int BatchInstruction::argumentsCount() const {
	return this->arguments.size();
}

BatchArgument * BatchInstruction::getArgument(int index) {
	return &this->arguments[index];
}

BatchArgument * BatchInstruction::getArgumentByName(string name) {
	for (int i = 0; i < this->arguments.size(); ++i) {
		if (this->arguments[i].getName() == name)
			return &this->arguments[i];
	}

	return NULL;
}

void BatchInstruction::addArgument(BatchArgument & arg) {
	this->arguments.push_back(arg);
	this->generateText();
}

void BatchInstruction::removeArgument(int index) {
	this->arguments.erase(this->arguments.begin() + index);
	this->generateText();
}

void BatchInstruction::removeArgument(BatchArgument & arg) {
	vector<BatchArgument>::iterator it;
	bool removed = false;

	while (!removed && it != this->arguments.end()) {
		if ((*it).equals(arg)) {
			this->arguments.erase(it);
			removed = true;
		}
		it++;
	}
}

bool BatchInstruction::has(string str) {
	if (this->text.find(str) != string::npos)
		return true;
	return false;
}

int BatchInstruction::indexOf(const BatchArgument * arg) {
	for (int i = 0; i < this->arguments.size(); ++i) {
		if (&(this->arguments[i]) == arg)
			return i;
	}

	return -1;
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com