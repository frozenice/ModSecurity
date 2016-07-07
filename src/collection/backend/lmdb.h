/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */


#ifdef __cplusplus
#include <string>
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#endif

#include <lmdb.h>

#include "modsecurity/collection/variable.h"
#include "modsecurity/collection/collection.h"

#ifndef SRC_COLLECTION_BACKEND_LMDB_H_
#define SRC_COLLECTION_BACKEND_LMDB_H_

#ifdef __cplusplus
namespace modsecurity {
namespace collection {
namespace backend {

class LMDB :
    public Collection {
 public:
    LMDB();
    ~LMDB();
    void store(std::string key, std::string value) override;

    bool storeOrUpdateFirst(const std::string &key,
        const std::string &value) override;

    bool updateFirst(const std::string &key,
        const std::string &value) override;

    void del(const std::string& key) override;

    std::string* resolveFirst(const std::string& var) override;

    void resolveSingleMatch(const std::string& var,
        std::vector<const Variable *> *l) override;
    void resolveMultiMatches(const std::string& var,
        std::vector<const Variable *> *l) override;
    void resolveRegularExpression(const std::string& var,
        std::vector<const Variable *> *l) override;

 private:
    MDB_env *m_env;
    MDB_dbi m_dbi;
    MDB_txn *m_txn;

};

}  // namespace backend
}  // namespace collection
}  // namespace modsecurity
#endif


#endif  // SRC_COLLECTION_BACKEND_LMDB_H_