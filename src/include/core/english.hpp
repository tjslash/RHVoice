/* Copyright (C) 2012  Olga Yakovleva <yakovleva.o.v@gmail.com> */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU Lesser General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU Lesser General Public License for more details. */

/* You should have received a copy of the GNU Lesser General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef RHVOICE_ENGLISH_HPP
#define RHVOICE_ENGLISH_HPP

#include "str.hpp"
#include "fst.hpp"
#include "dtree.hpp"
#include "lts.hpp"
#include "language.hpp"

namespace RHVoice
{
  class english: public language
  {
  public:
    explicit english(const language_info& info);

  private:
    void transcribe_word(item& word) const;
    void post_lex(utterance& u) const;

    void predict_accents_and_tones(utterance& u) const;
    void correct_pronunciation_of_articles(utterance& u) const;
    void correct_pronunciation_of_contractions(utterance& u) const;

    const fst cmulex_fst;
    const lts cmulex_lts;
    const fst lseq_fst;
    const dtree accents_dtree;
    const dtree tones_dtree;
  };

  class english_info: public language_info
  {
  public:
    explicit english_info(const std::string& data_path):
      language_info("English",data_path)
    {
      set_alpha2_code("en");
      set_alpha3_code("eng");
      register_letter_range('a',26);
      register_letter_range('A',26);
    }

  private:
    smart_ptr<language> create_instance() const;
  };
}
#endif