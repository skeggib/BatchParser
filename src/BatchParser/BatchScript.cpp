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

#include "BatchScript.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

BatchScript::BatchScript() {

}

BatchScript::BatchScript(const string & script) : BatchScript() {
	this->setScript(script);
}

void BatchScript::parse(const string & script) {
	string str(script);
	vector<string> vec = StrHelper::split(str, "\n");
	vector<string>::iterator it = vec.begin();

	while (it != vec.end()) {
		if (*it == "")
			vec.erase(it);
		else
			it++;
	}

	for (int i = 0; i < vec.size(); i++) {
		this->instructions.push_back(BatchInstruction(vec[i]));
	}
}

vector<BatchInstruction*> BatchScript::search(string str) {
	vector<BatchInstruction*> vec;

	for (int i = 0; i < this->instructions.size(); i++) {
		if (this->instructions[i].has(str))
			vec.push_back(&this->instructions[i]);
	}

	return vec;
}

int BatchScript::instructionsCount() {
	return this->instructions.size();
}

BatchInstruction* BatchScript::getInstruction(int index) {
	return &(this->instructions[index]);
}

string BatchScript::getScript() {
	string str = "";

	for (int i = 0; i < this->instructions.size(); i++) {
		str += this->instructions[i].getText() + "\n";
	}

	return str;
}

void BatchScript::setScript(string script) {
	this->parse(script);
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com
